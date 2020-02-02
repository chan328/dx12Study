#pragma once
#ifndef GAMETIMER_H
#define GAMETIMER_H

class GameTimer
{
public:
	GameTimer();

	float TotalTime()const; // 古段原陥
	float DeltaTime()const; // 古段原陥

	void Reset();
	void Start();
	void Stop();
	void Tick();

private:
	double mSecondsPerCount;
	double mDeltaTime;

	__int64 mBaseTime;
	__int64 mPausedTime;
	__int64 mStopTime;
	__int64 mPrevTime;
	__int64 mCurrTime;

	bool mStopped;
};
#endif // GAMETIMER_H