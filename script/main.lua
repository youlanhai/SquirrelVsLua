
function testEmptyFunCall()
	return 0
end

function testNumber(n)
	local a = 0.0
	for i = 1.0, n do
		a = i + 99.9
	end
	return a
end


local arraySize = 1000
local array = {}
for i = 1, arraySize do
	array[i] = "hello world"
end
function testArrayGetSet(n)
	for i = 1, n do
		array[6] = array[5]
	end
end


local strlen = 100
local strA = ""
local strB = ""
for i = 1, strlen do
	strA = strA .. "a"
	strB = strB .. "b"
end
function testStringConcat(n)
	local ret = nil
	for i = 1, n do
		ret = strA .. strB
	end
	return ret
end


function testTableCreate(n)
	local t = {}
	for i = 1, n do
		t[tostring(i)] = "hello world!"
	end
	return t
end

local tableSize = 1000
local table = testTableCreate(tableSize)
function testTableFind(n)
	local ret = nil
	for i = 0, n - 1 do
		ret = table[tostring(i % tableSize + 1)]
	end
	return ret
end

function testTableFailedFind(n)
	local ret = nil
	for i = 1, n do
		ret = table["not found"]
	end
	return ret
end

print("Hello Lua!")
