struct Point
{
	union {
		struct {
			float x;
			float y;
		};
		float pointList[2];
	};
};