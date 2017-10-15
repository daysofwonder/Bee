#!/usr/bin/python3

import sys
import plistlib  # https://docs.python.org/3/library/plistlib.html
import json
from string import Template

file_name = sys.argv[1]

with open(file_name, 'rb') as file:
    plist_root = plistlib.load(file)

bee_nodes = []


def parse_node(node):
    bee_node = {
        'clazz': "ui.node",
        'id': "",
        'children': [],
        'size': [],
        'x': 0,
        'y': 0,
    }
    if node["customClass"]:
        bee_node['clazz'] = node["customClass"]
    else:
        bee_node['clazz'] = node["baseClass"]

    bee_node['id'] = '"' + node["displayName"] + '"'
    bee_node['id'] = bee_node['id'].replace(" ", "_")

    for element_property in node["properties"]:
        if element_property["name"] == "contentSize":
            size = element_property["value"]
            bee_node['size'].append(size[0])
            bee_node['size'].append(size[1])
        elif element_property["name"] == "position":
            position = element_property["value"]
            bee_node['x'] = position[0]
            bee_node['y'] = position[1]
        elif element_property["name"] == "displayFrame":
            sprite_name = element_property["value"]
            bee_node['sprite'] = '"' + sprite_name[1] + '"'

    # Gor throught all children
    for child in node["children"]:
        bee_node['children'].append(parse_node(child))
    return bee_node


root = parse_node(plist_root["nodeGraph"])


# print(json.dumps(root, indent=4))

def process_node(node, deep):
    node_output = ''
    if node['clazz'] == "CCSprite":
        node['clazz'] = "ui:sprite"
    elif node['clazz'] == "CCNode":
        node['clazz'] = "ui:node"
    node_output += node['clazz'] + ' {\n'
    node_output += '\t' * deep
    node_output += 'id = ' + node['id']
    for key, value in node.items():
        if key == "id" or key == "size" or key == "children" or key == "clazz":
            continue
        node_output += ',\n' + ('\t' * deep)
        node_output += key + ' = ' + str(value)

    node_output += ',\n'
    if node['size']:
        node_output += ('\t' * deep)
        node_output += 'size = {%s, %s}' % (node['size'][0], node['size'][1])
        node_output += ',\n'
    if node['children']:
        node_output += ('\t' * deep) + "---- children ----\n"
        for child in node['children']:
            node_output += '\t' * (deep)
            node_output += process_node(child, deep + 1)
            node_output += ',\n'
    node_output += ('\t' * (deep - 1)) + '}'
    return node_output


output = "rootView = " + process_node(root, 1)
print(output)
