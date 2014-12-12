function is_prime(n)
  for i=2,n-1 do
    if n % i == 0 then
      return false
    end
  end
  return true
end

function is_palindrome(n)
  return tostring(n) == string.reverse(tostring(n))
end

for i=1000,0,-1 do
  if is_prime(i) and is_palindrome(i) then
    print(i)
    break
  end
end
