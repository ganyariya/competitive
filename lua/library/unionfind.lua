---https://github.com/ganyariya/competitive/tree/main/lua/library/unionfind.lua
---@class UnionFind
---@field par number[]
---@field sizes number[]
local UnionFind = {}

---@param self UnionFind
---@param n number
UnionFind.create = function(self, n)
    self.par = {}
    self.sizes = {}
    for i = 1, n do
        self.par[i] = i
        self.sizes[i] = 1
    end
end

---@param x number
UnionFind.Find = function(self, x)
    if self.par[x] == x then
        return x
    else
        local p = self:Find(self.par[x])
        self.par[x] = p
        return p
    end
end

---@param x number
---@param y number
UnionFind.Unite = function(self, x, y)
    x, y = self:Find(x), self:Find(y)
    if x == y then return false end
    if self.sizes[x] < self.sizes[y] then x, y = y, x end
    self.par[y] = x
    self.sizes[x] = self.sizes[x] + self.sizes[y]
    return true
end

---@param x number
---@param y number
UnionFind.Same = function(self, x, y)
    return self:Find(x) == self:Find(y)
end

---@param x number
UnionFind.GetSize = function(self, x)
    return self.sizes[self:Find(x)]
end

UnionFind.AllSame = function(self)
    local ok = true
    for i = 1, #self.par do
        if self:Find(1) ~= self:Find(i) then
            ok = false
        end
    end
    return ok
end

UnionFind.GetConnectivity = function(self)
    local tb = {}
    local cnt = 0
    for i = 1, #self.par do
        local v = self:Find(i)
        if tb[v] == nil then cnt = cnt + 1 end
        tb[v] = true
    end
    return cnt
end

---@param self UnionFind
---@param n number
---@return UnionFind
UnionFind.New = function(self, n)
    local obj = {}
    setmetatable(obj, { __index = UnionFind })
    obj:create(n)
    return obj
end

return UnionFind
