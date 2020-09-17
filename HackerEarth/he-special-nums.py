"""MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:,'..'xXWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .:kOo.,kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .lNWWo..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MNOxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMMMMWKxoloxKWNc  .:xxd;  ,dxxxkXMXkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMM
MKc''''''''''''''''.  ..'''''.   .''''.  .''MMMWx..,:. .xXo''.  .''.  ..'';kMk;'''''.  .'.''.  .''''''.  ..''.   .''MM
MWNXNNNNNNNNNNNNNNNO' ;KNNNNNKo. cKNNNd. lXNMMMK; ,0Wx. :NWXXl .dNNO' ;KNNNWMWNNNNNXc .kNNNNx. cXNNNNNO' ;KNN0; 'ONNMM
MMMMMMMMMMMMMMMMMWM0' :NMMMMWMX: .OMWWx. oWMMMMWx. ';. .dNMWWo .xMM0' :NWWMMMMMMMMWWl .OMMMWk. lWWMMWM0' ;XMMX: ,KMMMM
MMMMMMWMWkccccccccc;. :NMWNNNKd. :XMMWx. oWMMMWKo. .',. .,ldx; .dMM0' :NMMMMMMMNNWMWl .OMMMWk. lWMMMMM0' ;XMMX: ,0MMMM
MMWXKNWMWxcc,. .;cc;. :XMk,''..'lKWMMWx. oWMNx:. .lONNKxl.     .xMM0' :NMMMMMM0:,oKO' ,KMMMMk. lWWNkoc,. .;::;. ,KMMMM
MMXc.lXMMWWWNd..xWM0' :NM0;  ;kXWMMMWNl  oWMK:.;xXWWMWXx:. ,c' .dMM0' :NMMMMMMKc. ...;kWMMMMk. lWWc .:;. .clc:. ,KMMMM
MWWx. lXMWMMMK, lWM0' :NMMNx'.,ldxxoc'   oWMWNKNWWWN0o' .:kNWo .dMM0' :NMMMMMMMNO;  ,OWWWMMMk. lWM' lXx. lNMMX: ,KMMMM
MMMWk'.,xKNX0c..kWM0' :NMMMMNkl;,'',:l:  oWMMMMMWMWO' 'l0WMWWo .xMM0' :NMMMMMMMMMNd. .oXWMMMk. lWMd.....;0WMMX: ,KMMMM
MMMMWKo'...'..:kWMM0' :NMMMMMMMWWNNWWWx. oWMMMMMMMMWOxXWMWMWWo .xMM0' :NMMMMMMMMMMMKl. ,kNMMk. lWMWKkxx0NMWMMX: ,KMMMM
MMMMMMMN0kxk0XNWMMWKl;xNMMMMMMMMMMMMWM0c;kWMMMMMMMMMMMWWMMMMWk;:OMMXl,dNMMMMMMMMMMMMWO; .dNM0c;kWWMMMMMMMMMMMNd,oXMMMM
MMMMMMMMWWMWMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMWWMMWMMMMMMMMMMMMMMNkxKWMMWWMMMMMMMMMMMMMMWMMWMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"""


#				 Author: Udit "luctivud" Gupta @ https://www.linkedin.com/in/udit-gupta-1b7863135/					 #


import math;   		from collections import *
import sys;   		from functools import reduce
import time;   		from itertools import groupby

# sys.setrecursionlimit(10**6)

# def input()         : return sys.stdin.readline()
def get_ints()      : return map(int, input().strip().split())
def get_list()      : return list(get_ints())
def get_string()    : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")


DIRECTIONS = [(+0, +1), (+0, -1), (+1, +0), (+1, -1)] 
NEIGHBOURS = [(-1, -1), (-1, +0), (-1, +1), (+0, -1),\
              (+1, +1), (+1, +0), (+1, -1), (+0, +1)]



def getValidChars(k):
	temp = ord(k)
	k = int(k)
	valid_chars = [ord('0')]
	while temp <= ord('9'):
		valid_chars.append(temp)
		temp += k
	return valid_chars


def upper_bound(digit):
	pos = 0
	while pos < length_of_valid_chars and valid_chars[pos] < digit:
		pos += 1
	return pos

def lower_bound(digit):
	pos = 0
	while pos < length_of_valid_chars and valid_chars[pos] <= digit:
		pos += 1
	return pos

def greater_than(digit):
	return length_of_valid_chars - lower_bound(ord(digit))

def greater_or_equal(digit):
	return length_of_valid_chars - upper_bound(ord(digit))

def lesser_or_equal(digit):
	return lower_bound(ord(digit))

def lesser_than(digit):
	return upper_bound(ord(digit))

def betweenTwoDigitsExclusive(digitL, digitR):
	digitL = ord(digitL)
	digitR = ord(digitR)
	res = 0
	for i in valid_chars:
		if digitL < i < digitR:
			res += 1
	return res



def solveForGreater(index, seq, stop):
	if index == stop-1:
		return greater_or_equal(seq[index])
	if ord(seq[index]) in valid_chars:
		return solveForGreater(index+1, seq, stop) + greater_than(seq[index]) * \
		((length_of_valid_chars)**(length_of_a - index - 1))
	else:
		return greater_than(seq[index]) * \
		((length_of_valid_chars)**(length_of_a - index - 1))

def solveForLesser(index, seq, stop):
	if index == stop-1:
		return lesser_or_equal(seq[index])
	if ord(seq[index]) in valid_chars:
		return solveForLesser(index+1, seq, stop) + lesser_than(seq[index]) * \
		((length_of_valid_chars)**(length_of_a - index - 1))
	else:
		return lesser_than(seq[index]) * \
		((length_of_valid_chars)**(length_of_a - index - 1))


# MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

for _test_ in range(int(input())): 
	a, b, k = input().split()
	valid_chars = getValidChars(k)
	length_of_valid_chars = len(valid_chars)
	# print(list(map(chr, valid_chars)))
	# print(valid_chars)
	length_of_b = len(b)
	# print(greater_or_equal('6'))
	# g = '1'
	# g = (g.rjust(5, '0'))
	# print(type(a), b, g)
	a = a.rjust(length_of_b, '0')
	# print(a, b)
	length_of_a = len(a)
	# if length_of_b == length_of_a:
	mismatch = length_of_a
	ok = True
	for i in range(length_of_a):
		if a[i] == b[i] and ord(a[i]) in valid_chars:
			continue
		elif a[i] == b[i]:
			ok = False
			break
		elif a[i] != b[i]:
			mismatch = i
			break
	if not ok :
		print(0)
	else:
		ans = betweenTwoDigitsExclusive(a[mismatch], b[mismatch]) * \
				((length_of_valid_chars)**(length_of_a - mismatch - 1))
		if ord(a[mismatch]) in valid_chars:
			ans += solveForGreater(mismatch+1, a, length_of_a)
			
		if ord(b[mismatch]) in valid_chars:
			ans += solveForLesser(mismatch+1, b, length_of_b)

		print(ans)
	# else:
	# 	print("ok")



