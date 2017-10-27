CMAKE_MINIMUM_REQUIRED(VERSION 3.2 FATAL_ERROR)

ADD_LIBRARY(BeeCocos2dx
		src/bee/acme/Color.h
		src/bee/acme/RGBA.cpp src/bee/acme/RGBA.h
		src/bee/Cocos2dxBeehive.cpp include/bee/Cocos2dxBeehive.h
		src/bee/Graph.cpp src/bee/Graph.h
		src/bee/Label.cpp src/bee/Label.h
		src/bee/Node.cpp include/bee/Node.h
		src/bee/Rect.cpp src/bee/Rect.h
		src/bee/Sprite.cpp src/bee/Sprite.h
		)

ADD_LIBRARY(Bee::Cocos2dx ALIAS BeeCocos2dx)

SET_TARGET_PROPERTIES(BeeCocos2dx PROPERTIES
		CXX_STANDARD 14
		)

TARGET_INCLUDE_DIRECTORIES(BeeCocos2dx PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
		$<INSTALL_INTERFACE:include/>
		PRIVATE src/
		)


TARGET_LINK_LIBRARIES(BeeCocos2dx
		PRIVATE Lua cocos2dx
		PUBLIC Bee
		)
