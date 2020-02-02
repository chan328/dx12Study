#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "{" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport)
	{
		cout << "DirectXMath�� �������� ����" << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// ���� ����
	XMVECTOR a = u + v;

	// ���� ����
	XMVECTOR b = u - v;

	// ��Į�� ��
	XMVECTOR c = 10.0f * u;

	// ||u||
	XMVECTOR L = XMVector3Length(u);

	// d = u / |u|
	XMVECTOR d = XMVector3Normalize(u);

	// ����
	XMVECTOR s = XMVector3Dot(u, v);

	// ����
	XMVECTOR e = XMVector3Cross(u, v);

	// proj_n, perp_n(w) ���� ���Ѵ�.
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// projW + perpW == w?
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// projW, perpW ������ ������ �ݵ�� 90������ ��.
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	return 0;
}