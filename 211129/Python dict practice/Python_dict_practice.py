from typing import Type


dictname = {'A':'1','B':'2','C':'3','D':'4'}
print(dictname)

print(dictname['B'])

print(dictname.keys())
print(dictname.values())

dictname['E']='5'
print(dictname)

del dictname['B']
print(dictname)

print(dictname.pop('D'))
print(dictname)

print(len(dictname))
print(type(dictname))