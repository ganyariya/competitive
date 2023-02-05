---@param name string
---@return string
local function hello(name)
    return "Hello, World! " .. name
end

return {
    hello = hello
}
