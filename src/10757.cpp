/* 
*** solved by python ***

a, b = input().split()
length = min(len(a), len(b))


carry = 0
rem = 0
res = ''
for i in range(length) :
    s = int(a[len(a) - 1]) + int(b[len(b) - 1]) + carry
    rem = s % 10
    carry = s//10
    res = str(rem) + res
    a = a[:len(a) - 1]; b = b[:len(b) - 1]

    if len(a) < len(b) :
        s = b
        s = str(int(s) + carry)
        elif len(a) > len(b) :
        s = a
        s = str(int(s) + carry)
    else:
if carry == 1 : s = '1'
else : s = ''

res = s + res

while res[0] == '0' :
    res = res[1:]
    print(res)


*/
