
function testEmptyFunCall(){
	return 0
}

function testNumber(n){
	local a = 0.0
	local m = n + 0.1
	for(local i = 0.1; i < m; ++i){
		a = i + 99.9
	}
	return a
}


local arraySize = 1000
local array = []
for(local i = 0; i < arraySize; ++i){
	array.append("hello world")
}
function testArrayGetSet(n){
	for(local i = 0; i < n; ++i){
		array[6] = array[5]
	}
}


local strlen = 100
local strA = ""
local strB = ""
for(local i = 0; i < strlen; ++i){
	strA = strA + "a"
	strB = strB + "b"
}
function testStringConcat(n){
	local ret = null
	for(local i = 0; i < n; ++i){
		ret = strA + strB
	}
	return ret
}


function testTableCreate(n){
	local t = {}
	for(local i = 0; i < n; ++i){
		t[i.tostring()] <- "hello world!"
	}
	return t
}

local tableSize = 1000
local table = testTableCreate(tableSize)
function testTableFind(n){
	local ret = null
	for(local i = 0; i < n; ++i){
		local k = i % tableSize
		ret = table[k.tostring()]
	}
	return ret
}

function testTableFailedFind(n){
	local ret = null
	for(local i = 0; i < n; ++i){
		ret = table.rawin("not found")
	}
	return ret
}

print("Hello Squirrel!\n")
