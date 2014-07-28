import collection.immutable.HashMap
import collection.immutable.HashSet

object Solution {
  // for parsing
  // must try in order: parse_command, parse_rule, parse_query
  class Stream(val string:String) {
    var i = 0
    def parse_exact(token:String) : Boolean = {
      val j = i
      while (i < string.size && (i-j) < token.size && string(i) == token(i-j)) i += 1
      return if (i-j == token.size) true else { i = j; false }
    }
    def parse_word : Option[String] = {
      val j = i
      while (i < string.size && (string(i).isLetter || string(i).isDigit || string(i) == '-')) i += 1
      return if (j == i) None else Option(string.slice(j,i))
    }
    def parse_variable : Option[Variable] = {
      return if (parse_exact("#")) Option(new Variable(parse_word.get)) else None
    }
    def parse_name : Option[Name] = {
      return parse_word match {
        case Some(word) => Option(new Name(word))
        case None       => None
      }
    }
    def parse_relation : Option[Relation] = {
      return if (!parse_exact("[")) None
      else {
        val name = parse_word.get
        parse_exact(": ")
        val args = parse_simple_terms
        parse_exact("]")
        Option(new Relation(name,args))
      }
    }
    def parse_simple_term : Option[SimpleTerm] = {
      return parse_variable match {
        case Some(v) => Option(v)
        case None => parse_name match {
          case Some(n) => Option(n)
          case None => parse_relation
        }
      }
    }
    def parse_simple_terms : Vector[SimpleTerm] = {
      var terms = Vector[SimpleTerm]()
      var term = parse_simple_term
      while (term.isDefined) {
        parse_exact(", ")
        terms :+= term.get
        term = parse_simple_term
      }
      return terms
    }
    def parse_equal_or_not_equal : Option[EqualOrNotEqual] = {
      return if (!parse_exact("<")) None
      else {
        val lhs = parse_simple_term.get
        if (parse_exact(" = ")) {
          val rhs = parse_simple_term.get
          parse_exact(">")
          Option(new Equal(lhs,rhs))
        } else {
          parse_exact(" /= ")
          val rhs = parse_simple_term.get
          parse_exact(">")
          Option(new NotEqual(lhs,rhs))
        }
      }
    }
    def parse_complex_term : Option[ComplexTerm] = {
      return parse_simple_term match {
        case Some(t) => Option(t)
        case None => parse_equal_or_not_equal
      }
    }
    def parse_complex_terms : Vector[ComplexTerm] = {
      var terms = Vector[ComplexTerm]()
      var term = parse_complex_term
      while (term.isDefined) {
        parse_exact(", ")
        terms :+= term.get
        term = parse_complex_term
      }
      return terms
    }
    def parse_rule : Option[Rule] = {
      return parse_simple_term match {
        case Some(t) => {
          parse_exact(".")
          Option(new Rule(new Query(Vector()),t))
        }
        case None => {
          if (!parse_exact("{(")) None
          else {
            val premise = new Query(parse_complex_terms)
            parse_exact(") => ")
            val conclusion = parse_simple_term.get
            parse_exact("}.")
            return Option(new Rule(premise,conclusion))
          }
        }
      }
    }
    def parse_query : Option[Query] = {
      return if (!parse_exact("(")) None
      else {
        val q = new Query(parse_complex_terms)
        parse_exact(")?")
        Option(q)
      }
    }
    def parse_command : Boolean = {
      return parse_exact("quit!")
    }
  }
  
  var rules = Vector[Rule]()
  var rule_apply_invocation_count = 0
  
  def display(unfiltered_bindings:Vector[Map[String,SimpleTerm]]) {
    // println(unfiltered_bindings)
    if (unfiltered_bindings.isEmpty) {
      println("UNSAT")
    } else if (unfiltered_bindings.size == 1 && unfiltered_bindings.head.filter(_._1(0) != '*').isEmpty) {
      println("SAT")
    } else {
      for (unfiltered_binding <- unfiltered_bindings) {
        val filtered_binding = unfiltered_binding.filter(_._1(0) != '*')
        println("SAT:")
        println("=====")
        for (name <- filtered_binding.keySet.toVector.sorted) {
          println("#" + name + " := " + filtered_binding(name).resolve(unfiltered_binding))
        }
      }
    }
    println("Ready.")
  }
  
  // main
  def main(args:Array[String]) {
    for (ln <- scala.io.Source.stdin.getLines) {
      val s = new Stream(ln)
      if (s.parse_command) {
        println("Bye.")
      } else s.parse_rule match {
        case Some(rule) => { rules :+= rule; println("Ok.") }
        case None => s.parse_query match {
          case Some(query) => { display(query.prove) }
          case None => {} // do nothing if comment
        }
      }
    }
  }
  
  // logic
  abstract class ComplexTerm {
    def kind : String
    def args : Vector[SimpleTerm] = Vector() // meaningful only for Relation
    def lhs  : SimpleTerm = new Name("lhs")  // meaningful only for Equal/NotEqual
    def rhs  : SimpleTerm = new Name("rhs")  // meaningful only for Equal/NotEqual
    def substitute(name:String,term:SimpleTerm) : ComplexTerm
    def toSimpleTerm : SimpleTerm = { new Name("SimpleTerm") } // meaningful only for SimpleTerm
    def variables : Set[String]
    def qualify_variables : ComplexTerm
    def resolve(binding:Map[String,SimpleTerm]) : ComplexTerm
  }
  abstract class SimpleTerm(val name:String) extends ComplexTerm {
    override def substitute(name:String,term:SimpleTerm) : SimpleTerm
    def literally_equal(term:SimpleTerm) : Boolean = { superficially_equal(term) }
    def superficially_equal(term:SimpleTerm) : Boolean = {
      kind == term.kind && name == term.name && args.size == term.args.size
    }
    override def toSimpleTerm : SimpleTerm = { this }
    override def qualify_variables : SimpleTerm
    override def resolve(binding:Map[String,SimpleTerm]) : SimpleTerm
  }
  class Name(name:String) extends SimpleTerm(name) {
    def kind = { "Name" }
    override def substitute(name:String,term:SimpleTerm) : Name = { this }
    override def variables : Set[String] = { HashSet() }
    override def toString : String = { name }
    override def qualify_variables : Name = { this }
    override def resolve(binding:Map[String,SimpleTerm]) : SimpleTerm = { this }
  }
  class Variable(name:String) extends SimpleTerm(name) {
    def kind = { "Variable" }
    override def substitute(name:String,term:SimpleTerm) : SimpleTerm = {
      return if (this.name == name) term else this
    }
    override def variables : Set[String] = { HashSet(name) }
    override def toString : String = { "#" + name }
    override def qualify_variables : Variable = { new Variable("*"+rule_apply_invocation_count+"*"+name)}
    override def resolve(binding:Map[String,SimpleTerm]) : SimpleTerm = { if (binding.contains(name)) binding(name).resolve(binding) else this }
  }
  class Relation(name:String,override val args:Vector[SimpleTerm]) extends SimpleTerm(name) {
    def kind = { "Relation" }
    override def substitute(name:String,term:SimpleTerm) : Relation = {
      return new Relation(this.name,args.map(_.substitute(name,term)))
    }
    override def literally_equal(term:SimpleTerm) : Boolean = {
      superficially_equal(term) &&
        args.zip(term.args).forall((pair) => pair._1.literally_equal(pair._2))
    }
    override def variables : Set[String] = { args.map(_.variables)reduce((a:Set[String],b:Set[String]) => a ++ b) }
    override def toString : String = { "[" + name + ": " + args.mkString(", ") + "]" }
    override def qualify_variables : Relation = { new Relation(name,args.map(_.qualify_variables)) }
    override def resolve(binding:Map[String,SimpleTerm]) : SimpleTerm = { new Relation(name,args.map(_.resolve(binding))) }
  }
  abstract class EqualOrNotEqual(override val lhs:SimpleTerm,override val rhs:SimpleTerm) extends ComplexTerm {
    override def variables : Set[String] = { lhs.variables ++ rhs.variables } 
  }
  class Equal(lhs:SimpleTerm,rhs:SimpleTerm) extends EqualOrNotEqual(lhs,rhs) {
    def kind = { "Equal" }
    override def substitute(name:String,term:SimpleTerm) : Equal = {
      return new Equal(lhs.substitute(name, term),rhs.substitute(name, term))
    }
    override def toString : String = { "<" + lhs + " = " + rhs + ">" }
    override def qualify_variables : Equal = { new Equal(lhs.qualify_variables,rhs.qualify_variables) }
    override def resolve(binding:Map[String,SimpleTerm]) : Equal = { new Equal(lhs.resolve(binding),rhs.resolve(binding)) }
  }
  class NotEqual(lhs:SimpleTerm,rhs:SimpleTerm) extends EqualOrNotEqual(lhs,rhs) {
    def kind = { "NotEqual" }
    override def substitute(name:String,term:SimpleTerm) : NotEqual = {
      return new NotEqual(lhs.substitute(name, term),rhs.substitute(name, term))
    }
    override def toString : String = { "<" + lhs + " /= " + rhs + ">" }
    override def qualify_variables : NotEqual = { new NotEqual(lhs.qualify_variables,rhs.qualify_variables) }
    override def resolve(binding:Map[String,SimpleTerm]) : NotEqual = { new NotEqual(lhs.resolve(binding),rhs.resolve(binding)) }
  }
  
  def unify(lhs:SimpleTerm,rhs:SimpleTerm) : Option[Map[String,SimpleTerm]] = { return unify(Vector(new Equal(lhs,rhs))) }
  
  def unify(pairs:Vector[Equal]) : Option[Map[String,SimpleTerm]] = {
    // base-case : if there are no pairs to unify, an empty binding satisfies
    if (pairs.isEmpty) return Option(Map())
    
    val pair = pairs.head
    val lhs = pair.lhs
    val rhs = pair.rhs
    val tail = pairs.tail
    // unify with no extra bindings if 
    if (lhs.literally_equal(rhs)) return unify(pairs.tail)
    
    // We have a variable to assign.
    if (lhs.kind == "Variable") {
      // occurs check
      if (rhs.kind == "Relation" && rhs.variables.contains(lhs.name)) return None
      
      // "set" the variable
      return unify(tail.map(_.substitute(lhs.name,rhs))).map(_.updated(lhs.name,rhs))
    }
    
    // if the right side is a variable but not the left side, try again with terms swapped
    else if (rhs.kind == "Variable") {
      return unify(tail.+:(new Equal(rhs,lhs)))
    }
    
    // If we superficially match, but not literally, we have two relations
    if (lhs.superficially_equal(rhs)) {
      // We "unzip" the arguments and add them to the list of equality relations to unify
      return unify(lhs.args.zip(rhs.args).map((p) => {val (l,r)=p; new Equal(l,r) }) ++ pairs)
    }
    
    // If none of the above applies, fail unification.
    return None
  }
  
  class Rule(val premise:Query,val conclusion:SimpleTerm) {
    override def toString() : String = { "{(" + premise.terms.mkString(", ") + ") => " + conclusion + "}." }
    def resolve(binding:Map[String,SimpleTerm]) : Rule = { new Rule(premise.resolve(binding),conclusion.resolve(binding))}
    def qualify_variables : Rule = {
      new Rule(premise.qualify_variables,conclusion.qualify_variables)
    }
    def apply(term:SimpleTerm) : Vector[Map[String,SimpleTerm]] = {
      rule_apply_invocation_count += 1
      return qualify_variables.apply0(term)
    }
    def apply0(term:SimpleTerm) : Vector[Map[String,SimpleTerm]] = {
      // In order to apply a rule to a term,
      // unify the term with the conclusion,
      unify(term,conclusion) match {
        case Some(conclusion_binding) => {
          val bound_premise = premise.resolve(conclusion_binding)
          val premise_bindings = bound_premise.prove // then try to prove the premise
          premise_bindings.map(_.++(conclusion_binding))
        }
        case None => Vector() // if your conclusion doesn't apply, there are no valid bindings
      }
    }
  }
  
  class Query(val terms:Vector[ComplexTerm]) {
    override def toString() : String = { "(" + terms.mkString(", ") + ")?" }
    def resolve(bindings:Map[String,SimpleTerm]) : Query = { new Query(terms.map(_.resolve(bindings))) }
    def prove : Vector[Map[String,SimpleTerm]] = {
      // If there is nothing to prove, an empty binding does the job
      if (terms.isEmpty) return Vector(Map())
      
      val term = terms.head
      val tail = terms.tail
      
      // first collect all the bindings resulting from just the first term
      val bindings = term.kind match {
        case "Equal" => {
          unify(term.lhs,term.rhs) match {
            case Some(binding) => Vector(binding)
            case None => Vector()
          }
        }
        case "NotEqual" => {
          // NotEqual is kind of weird in that a check has to come after everything else matches.
          val (lhs,rhs) = (term.lhs,term.rhs)
          
          // First of all, we may prune out cases in which the final result will have to be equal
          if (lhs.literally_equal(rhs)) return Vector()
          
          // (new Query(tail).prove) will find all bindings pretending this NotEqual isn't here.
          // Afterwards we filter out all those bindings that force the left and right sides to be equal.
          // return new Query(tail).prove.filter((binding) => !lhs.resolve(binding).literally_equal(rhs.resolve(binding)))
          
          // Hmm. One test case stubbornly refuses to pass. Perhaps I should be more aggressive and filter out
          // any binding that allows the two sides to unify?
          return new Query(tail).prove.filter((binding) => unify(lhs.resolve(binding),rhs.resolve(binding)) == None)
        }
        case _ => {
          // "term" is a SimpleTerm. To prove it, we walk over each rule and collect all bindings
          rules.map((rule) => rule.apply(term.toSimpleTerm)).fold(Vector())((a,b) => a ++ b)
        }
      }
      
      // Now we recurse down each binding to the other terms
      return bindings.map((binding) => new Query(tail.map(_.resolve(binding))).prove.map(_.++(binding))).fold(Vector())((a,b) => a ++ b)
    }
    def qualify_variables : Query = { new Query(terms.map(_.qualify_variables)) }
  }
  
}