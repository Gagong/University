----------------------------------------------------
-- 1. Variables and flow control.
----------------------------------------------------

num = 42
s = 'walternate' 
t = "double-quotes are also fine"
u = [[ Double brackets
       start and end
       multi-line strings.]]
t = nil

-- Blocks are denoted with keywords like do/end:
while num < 50 do
  num = num + 1
end

-- If clauses:
if num > 40 then
  print('over 40')
elseif s ~= 'walternate' then
  io.write('not over 40\n')
else
  thisIsGlobal = 5
  local line = io.read()
  print('Winter is coming, ' .. line)
end

foo = anUnknownVariable
aBoolValue = false

if not aBoolValue then print('it was false') end
ans = aBoolValue and 'yes' or 'no'  --> 'no'

karlSum = 0
for i = 1, 100 do 
  karlSum = karlSum + i
end

fredSum = 0
for j = 100, 1, -1 do fredSum = fredSum + j end

repeat
  print('the way of the future')
  num = num - 1
until num == 0

----------------------------------------------------
-- 2. Functions.
----------------------------------------------------

function fib(n)
  if n < 2 then return 1 end
  return fib(n - 2) + fib(n - 1)
end

function adder(x)
  return function (y) return x + y end
end
a1 = adder(9)
a2 = adder(36)
print(a1(16)) 
print(a2(64)) 

x, y, z = 1, 2, 3, 4

function bar(a, b, c)
  print(a, b, c)
  return 4, 8, 15, 16, 23, 42
end

x, y = bar('zaphod')

function f(x) return x * x end
f = function (x) return x * x end

local function g(x) return math.sin(x) end
local g; g = function (x) return math.sin(x) end
print 'hello' 

----------------------------------------------------
-- 3. Tables.
----------------------------------------------------

t = {key1 = 'value1', key2 = false}
print(t.key1)
t.newKey = {}
t.key2 = nil

u = {['@!#'] = 'qbert', [{}] = 1729, [6.28] = 'tau'}
print(u[6.28]) 

a = u['@!#']
b = u[{}]

function h(x) print(x.key1) end
h{key1 = 'Sonmi~451'}

for key, val in pairs(u) do 
  print(key, val)
end

print(_G['_G'] == _G)

v = {'value1', 'value2', 1.21, 'gigawatts'}
for i = 1, #v do 
  print(v[i]) 
end

----------------------------------------------------
-- 3.1 Metatables and metamethods.
----------------------------------------------------

f1 = {a = 1, b = 2} 
f2 = {a = 2, b = 3}

metafraction = {}
function metafraction.__add(f1, f2)
  sum = {}
  sum.b = f1.b * f2.b
  sum.a = f1.a * f2.b + f2.a * f1.b
  return sum
end

setmetatable(f1, metafraction)
setmetatable(f2, metafraction)

s = f1 + f2 

defaultFavs = {animal = 'gru', food = 'donuts'}
myFavs = {food = 'pizza'}
setmetatable(myFavs, {__index = defaultFavs})
eatenBy = myFavs.animal

----------------------------------------------------
-- 3.2 Class-like tables and inheritance.
----------------------------------------------------

Dog = {}                                   

function Dog:new()                         
  newObj = {sound = 'woof'}                
  self.__index = self                      
  return setmetatable(newObj, self)        
end

function Dog:makeSound()                   
  print('I say ' .. self.sound)
end

mrDog = Dog:new()                          
mrDog:makeSound()     

LoudDog = Dog:new()                           

function LoudDog:makeSound()
  s = self.sound .. ' '                       
  print(s .. s .. s)
end

seymour = LoudDog:new()                       
seymour:makeSound()  

function LoudDog:new()
  newObj = {}
  -- set up newObj
  self.__index = self
  return setmetatable(newObj, self)
end

