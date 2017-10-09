--
-- User: Dawid Drozd aka Gelldur
-- Date: 08.10.17
--

ui = {}

_Node = {}
_RGBA = {}

function _Node.setNode(node, content)
	node:setPosition(content["x"] or 0.0, content["y"] or 0.0)
	if content["size"] then
		node:setSize(content["size"][1], content["size"][2])
	end
	for key, value in pairs(content)
	do
		if type(key) == "number" then
			node:addChild(value)
		end
	end
	return node
end

function _RGBA.setNode(node, content)
	if content["color"] then
		node:setColor(content["color"])
	end
	if content["opacity"] then
		node:setOpacity(content["opacity"])
	end
	return node
end

function ui.node(self, content)
	local node = Node.new(content["id"] or "")
	_Node.setNode(node, content)
	return node
end

function ui.sprite(self, content)
	local node = Sprite.new(content["id"])
	node:sprite(content["sprite"])

	_RGBA.setNode(node, content)
	_Node.setNode(node:getNode(), content)

	return node:getNode()
end

function ui.rect(self, content)
	local node = Rect.new(content["id"])

	_RGBA.setNode(node, content)
	_Node.setNode(node:getNode(), content)

	return node:getNode()
end

function ui.label(self, content)
	local node = Label.new(content["id"])

	if content["font"] then
		node:setFont(content["font"])
	end
	if content["fontSize"] then
		node:setFontSize(content["fontSize"])
	end
	if content["text"] then
		node:setText(content["text"])
	end
	if content["align"] then
		node:setAlign(content["align"])
	end

	_RGBA.setNode(node, content)
	_Node.setNode(node:getNode(), content)

	return node:getNode()
end

return ui
