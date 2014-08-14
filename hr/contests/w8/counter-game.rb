require 'set'

POWERS_OF_TWO = (1...64).map {|i| 2 ** i}.to_set

def flip(answer)
  answer == 'Richard' ? 'Louise' : 'Richard'
end

def largest_power_of_two_less_than(n)
  POWERS_OF_TWO.select{|p| p < n}.max
end

def solve(n)
  return 'Richard' if n == 1
  return flip(solve(n/2)) if POWERS_OF_TWO.include?(n)
  return flip(solve(n - largest_power_of_two_less_than(n)))
end

gets.to_i.times do
  puts solve gets.to_i
end

