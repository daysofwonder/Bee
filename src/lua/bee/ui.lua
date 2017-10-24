--
-- User: Dawid Drozd aka Gelldur
-- Date: 08.10.17
--

ui = {}

_Node = {}

function _Node.setNode(node, content)
	node = node:getNode()
	if content["anchor"] then
		node:setAnchor(content["anchor"][1], content["anchor"][2])
	end
	node:setPosition(content["x"] or 0.0, content["y"] or 0.0)
	if content["size"] then
		node:setSize(content["size"][1], content["size"][2])
	end
	if content["visible"] then
		node:setVisible(content["visible"])
	end
	if content["rotation"] then
		node:setRotation(content["rotation"])
	end

	if content["scale"] then
		if type(content["scale"]) == "number" then
			node:setScale(content["scale"], content["scale"])
		else
			node:setScale(content["scale"]["x"] or 1, content["scale"]["y"] or 1)
		end
	end

	for key, value in pairs(content)
	do
		if type(key) == "number" then
			beehive.addRelation(node, value)
			node:addChild(value)
		end
	end
	return node
end

_RGBA = {}

function _RGBA.setNode(node, content)
	if content["color"] then
		node:setColor(content["color"])
	end
	if content["opacity"] then
		node:setOpacity(content["opacity"])
	end
	return node:getNode()
end

function ui.node(self, content)
	local node = Node.new(content["id"] or "")
	_Node.setNode(node, content)
	return node:getNode()
end

function ui.sprite(self, content)
	local node = Sprite.new(content["id"])
	node:sprite(content["sprite"])

	_RGBA.setNode(node, content)
	_Node.setNode(node, content)

	return node:getNode()
end

function ui.rect(self, content)
	local node = Rect.new(content["id"])

	_RGBA.setNode(node, content)
	_Node.setNode(node, content)

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
	_Node.setNode(node, content)

	return node:getNode()
end

return ui
