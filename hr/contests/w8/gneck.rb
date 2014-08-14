# require 'bigdecimal'
# require 'complex'
# #R0 = BigDecimal('1.4655712318767680266567312252199391080255775684722857016431831112492629966850178404781258011949')
# R0 = BigDecimal('1.4655712318767680266567312', 1)
# R1 = Complex(BigDecimal('-0.2327856159383840133283656', 1),BigDecimal('-0.7925519925154478483258983', 1))
# R2 = Complex(BigDecimal('-0.2327856159383840133283656', 1),BigDecimal( '0.7925519925154478483258983', 1))
# C0 = BigDecimal('1.313423059852349798783264', 1)
# C1 = Complex(BigDecimal('-0.1567115299261748993916320', 1),BigDecimal( '0.0013403336184118080951891', 1))
# C2 = Complex(BigDecimal('-0.1567115299261748993916320', 1),BigDecimal('-0.0013403336184118080951891', 1))
#
# def f n
#   (C0 * R0 ** n + C1 * R1 ** n + C2 * R2 ** n).real.round
# end
#
# p f(1000000)

# require 'complex'
# R0 = 1.4655712318767680266567312
# R1 = Complex(-0.2327856159383840133283656, -0.7925519925154478483258983)
# R2 = Complex(-0.2327856159383840133283656,0.7925519925154478483258983)
# C0 = 1.313423059852349798783264
# C1 = Complex(-0.1567115299261748993916320, 0.0013403336184118080951891)
# C2 = Complex(-0.1567115299261748993916320,-0.0013403336184118080951891)
# def f n
#   (C0 * R0 ** n + C1 * R1 ** n + C2 * R2 ** n).real.round
# end
#
# f 1000000

MEMO = [1, 2, 3]
M = 10 ** 9 + 7

def f n
  while MEMO.size <= n
    MEMO << ( (MEMO[-1] + MEMO[-3]) % M )
  end
  return MEMO[n]
end

gets.to_i.times do
  puts f(gets.to_i)
end
