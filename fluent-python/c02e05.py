import array

symbols = '$¢£¥€¤'
t = tuple(ord(symbol) for symbol in symbols)
a = array.array('I', (ord(symbol) for symbol in symbols))
print(t)
print(a)
