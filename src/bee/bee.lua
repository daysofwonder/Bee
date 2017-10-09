--
-- User: Dawid Drozd aka Gelldur
-- Date: 08.10.17
-- Time: 12:37
--

ui = {}

function ui.node(self, content)
	--print("ui.node ---")
	node = Node.new(content["id"] or "")
	node:setX(content["x"] or 0.0)
	node:setY(content["y"] or 0.0)
	node:setColor(content["color"] or 0x00000000)
	if content["size"] then
		node:setSize(content["size"][1], content["size"][2])
	end
	for key, value in pairs(content)
	do
		if type(key) == "number" then
			node:addChild(value)
		else
			print(key, value)
		end
	end

	return node
	--return function () end
end

function ui.sprite(self, content)
	--print("ui.sprite ---")
	node = Node.new(content["id"])
	node:sprite(content["sprite"] or "missing_sprite_arg")
	node:setX(content["x"] or 0.0)
	node:setY(content["y"] or 0.0)
	if content["size"] then
		node:setSize(content["size"][1], content["size"][2])
	end
	for key, value in pairs(content)
	do
		if type(key) == "number" then
			node:addChild(value)
		else
			print(key, value)
		end
	end

	return node
	--return function () end
end

return ui
