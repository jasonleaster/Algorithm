--[[---------------------------------------------
Programmer  :   EOF
Date        :   2015.06.28
File        :   set.lua
E-mail      :   jasonleaster@gmail.com
-------------------------------------------------]]

local function iter(a, i)
        i = i + 1
        local v  = a[i]
        if v then
            return i, v
        end
end

function ipairs(a)
    return iter, a, 0
end

function Set(list)
    local set = {}
    for _, l in ipairs(list) do 
        set[l] = true
    end

    return set
end

reserved = Set{"while", "end", "function", "local"}
