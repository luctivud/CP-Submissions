class IncorrectCancellation():

	def find(self, denom):
		self.allPos = []
		# denom = str(denom)
		def findallPos(pos, ind, denom):
			if ind == len(denom):
				if (len(pos) > 0 and pos[0] != '0'):
					self.allPos.append(int(pos))
				return
			findallPos(pos, ind+1, denom)
			findallPos(pos + denom[ind], ind + 1, (denom))
		findallPos('', 0, str(denom))

		# print(self.allPos)
		def computeGCD(x, y):
		   while(y):
		       x, y = y, x % y
		   return x
		  
		ALLDIGS = "0123456789"

		import collections
		cntDen = collections.Counter(str(denom))
		for i in self.allPos:
			if i == 0 or i == denom:
				continue;
			cntThis = collections.Counter(str(i))
			Den = (denom)
			Num = i
			gc = computeGCD(Num, Den)
			Num //= gc
			Den //= gc
			for digi in ALLDIGS:
				cntThis[digi] -= cntDen[digi]
			# print(i, Num, Den, denom, cntThis)
			for j in range(1, (denom)):
				if j * Den >= (denom):
					break
				cntJDen = collections.Counter(str(j * Den))
				cntNum = collections.Counter(str(Num))
				for digi in (ALLDIGS):
					cntNum[digi] -= cntJDen[digi]
				ok = True
				for digi in ALLDIGS:
					if (cntNum[digi] != cntThis[digi]):
						ok = False
						break
				if ok:
					return j * Den
			
				# if collections.Counter(str(j * Den)) - collections.Counter(str(Num)) == cntDen - cntThis:
				# 	return j * Den

		return -1





obj = IncorrectCancellation()
print(obj.find(15436))