#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include  <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
    XMFLOAT4 dest;
    XMStoreFloat4(&dest, v);

    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
    return os;
}

ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetX(m.r[i]);
		os << endl;
	}

	return os;
}

int main()
{
	if (!XMVerifyCPUSupport)
	{
		cout << "DirectXMath를 지원하지 않음" << endl;
		return 0;
	}

	XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		1.0f, 2.0f, 3.0f, 1.0f);

	XMMATRIX B = XMMatrixIdentity();

	XMMATRIX C = A * B;

	XMMATRIX D = XMMatrixTranspose(A);

	XMVECTOR det = XMMatrixDeterminant(A);
	XMMATRIX E = XMMatrixInverse(&det, A);

	XMMATRIX F = A * E;

	return 0;
}