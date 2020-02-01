#pragma once
class GameLayer {
public:
	virtual void Start() = 0; //Executes before render loop
	virtual void Update() = 0;
};