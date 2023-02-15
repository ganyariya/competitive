---https://github.com/LuaLS/lua-language-server/wiki/Annotations
---@class Queue
---@field data any[]
---@field first number
---@field last number
---@field cnt number
local Queue = {}

Queue.create = function(self)
    self.data, self.first, self.last, self.cnt = {}, 0, -1, 0
end

---@param x any
Queue.Push = function(self, x)
    self.last = self.last + 1
    self.data[self.last] = x
    self.cnt = self.cnt + 1
end

---@return any
Queue.Top = function(self)
    return self.data[self.first]
end

---@return any
Queue.Pop = function(self)
    if self.first > self.last then error("list is empty") end
    local x = self.data[self.first]
    self.data[self.first] = nil
    self.first = self.first + 1
    self.cnt = self.cnt - 1
    return x
end

Queue.Empty = function(self)
    return self.cnt == 0
end

---@return Queue
Queue.New = function()
    ---@type Queue
    local obj = {}
    setmetatable(obj, { __index = Queue })
    obj:create()
    return obj
end

return Queue
