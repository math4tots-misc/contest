
# Standard Error:
# Traceback (most recent call last):
#   File "Wrapper.py", line 186, in <module>
# NameError: name 'writeChar' is not defined

# http://apps.topcoder.com/forums/?module=Thread&threadID=824794&start=0&mc=2#1900367
# Looks like this problem is not solvable in Python...


class HappyLetterDiv2:
	def getHappyLetter(self,letters):
		counter = dict()
		for letter in letters:
			counter[letter] = counter.get(letter,0) + 1
		candidate = max(counter, key = lambda key : counter[key])
		return candidate if 2 * counter[candidate] > len(letters) else '.'
