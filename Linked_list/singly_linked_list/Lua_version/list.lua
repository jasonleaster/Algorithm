--[[------------------------------------------------------
Programmer  :   EOF
Date        :   2015.06.28
File        :   list.lua
E-mail      :   jasonleaster@gmail.com

--------------------------------------------------------]]

local list = nil
function ListNew()
    return list
end

function Insert(number)
    list = {next = list, value = number}
    return list
end


for i = 1, 10 do
    Insert(i)
end

local l = list
local str = ""
while l do
    str = str .. l.value .. "\t"
    l = l.next
end
print(str)
