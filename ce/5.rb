File.open(ARGV[0], "r") do |f|
  while line = f.gets
    d = {}
    ii = line.split.map(&:to_i).to_a
    ii[0..-2].zip(ii[1..-1]).each do |(key, value)|
      if d[key] == value
        x = key
        print "#{x}"
        x = value
        while x != key
          print " #{x}"
          x = d[x]
        end
        puts
        break
      end
      d[key] = value
    end
  end
end
