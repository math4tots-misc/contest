# https://www.hackerrank.com/challenges/detect-html-tags

# Problem
# Use regex to detect what tags are being used in an html document.

# Solution
# ...

require 'set'

N = gets.to_i
S = STDIN.read

# Remove String literals
# Who knows what sorts of things are in strings...
# However, stripping string literals this way seem to be taking away
# too much....
# So I guess I'll leave string literals in...
# Hopefully they are not a problem...
#S.gsub!(/\"((\\\")|[^"])*\"/,'')
#S.gsub!(/\'((\\\')|[^'])*\'/,'')

# And ... I guess it passed!
# So no weird stuff in string literals in the test cases.

#p /\<td\>/ =~ S

X = S.scan(/\<\s*\/?([a-zA-Z0-9]+)[^\>]*\>/).flatten.to_set

# As far as I understand, this sort of Markdown style links
# are not really html, but the problem seems to suggest
# I should treat them as such.
X << 'a' if S =~ /\[[^\]]*\]\([^\)]*\)/

puts X.to_a.sort.join(';')
