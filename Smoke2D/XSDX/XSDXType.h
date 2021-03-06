//--------------------------------------------------------------------------------------
// By Stars XU Tianchen
//--------------------------------------------------------------------------------------

#pragma once

#include <array>
#include "Common\DirectXHelper.h"

// Vector allocation and fit 
#define VEC_ALLOC(v, i)			{ v.resize(i); v.shrink_to_fit(); }
#define VEC_ALLOC_PTR(p, T, i)	{ p = make_shared<T>(); p->resize(i); p->shrink_to_fit(); }

// Dereference
#define DREF(p)					(*p)

namespace XSDX
{
	template<typename T>
	inline T& dref(std::shared_ptr<T> &p)
	{
		assert(p);
		return DREF(p);
	}

	template<typename T, size_t S>
	inline T& dref(std::_Array_iterator<T, S> &p)
	{
		assert(p._Ptr);
		return DREF(p);
	}

	template<typename T, size_t S>
	inline const T dref(std::_Array_const_iterator<T, S> &p)
	{
		assert(p._Ptr);
		return DREF(p);
	}

	template<typename T>
	inline T& dref(std::_Vector_iterator<T> &p)
	{
		assert(p._Ptr);
		return DREF(p);
	}

	template<typename T>
	inline const T dref(std::_Vector_const_iterator<T> &p)
	{
		assert(p._Ptr);
		return DREF(p);
	}

	template<typename T, typename = std::enable_if_t<std::is_pointer<T>::value>>
	inline typename std::remove_pointer_t<T>& dref(T p)
	{
		assert(p);
		return DREF(p);
	}

	//--------------------------------------------------------------------------------------
	// COM pointers of DirectX data types
	//--------------------------------------------------------------------------------------

	// Devices
	using CPDXDevice				= Microsoft::WRL::ComPtr<ID3D11Device>;
	using CPDXContext				= Microsoft::WRL::ComPtr<ID3D11DeviceContext>;

	// Shader resources (buffer and textures)
	using CPDXResource				= Microsoft::WRL::ComPtr<ID3D11Resource>;
	using CPDXBuffer				= Microsoft::WRL::ComPtr<ID3D11Buffer>;
	using CPDXTexture2D				= Microsoft::WRL::ComPtr<ID3D11Texture2D>;
	using CPDXShaderResourceView	= Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>;
	using CPDXRenderTargetView		= Microsoft::WRL::ComPtr<ID3D11RenderTargetView>;
	using CPDXDepthStencilView		= Microsoft::WRL::ComPtr<ID3D11DepthStencilView>;
	using CPDXUnorderedAccessView	= Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView>;

	// Shaders
	using CPDXVertexShader			= Microsoft::WRL::ComPtr<ID3D11VertexShader>;
	using CPDXHullShader			= Microsoft::WRL::ComPtr<ID3D11HullShader>;
	using CPDXDomainShader			= Microsoft::WRL::ComPtr<ID3D11DomainShader>;
	using CPDXGeometryShader		= Microsoft::WRL::ComPtr<ID3D11GeometryShader>;
	using CPDXPixelShader			= Microsoft::WRL::ComPtr<ID3D11PixelShader>;
	using CPDXComputeShader			= Microsoft::WRL::ComPtr<ID3D11ComputeShader>;

	// Shader reflector
	using CPDXReflector				= Microsoft::WRL::ComPtr<ID3D11ShaderReflection>;

	// States
	using CPDXBlendState			= Microsoft::WRL::ComPtr<ID3D11BlendState>;
	using CPDXDepthStencilState		= Microsoft::WRL::ComPtr<ID3D11DepthStencilState>;
	using CPDXRasterizerState		= Microsoft::WRL::ComPtr<ID3D11RasterizerState>;
	using CPDXSamplerState			= Microsoft::WRL::ComPtr<ID3D11SamplerState>;

	// Input assembler
	using CPDXInputLayout			= Microsoft::WRL::ComPtr<ID3D11InputLayout>;

	// Blob
	using CPDXBlob					= Microsoft::WRL::ComPtr<ID3DBlob>;

	//--------------------------------------------------------------------------------------
	// Pointers
	//--------------------------------------------------------------------------------------

	// Devices
	using LPDXDevice				= std::add_pointer_t<ID3D11Device>;
	using LPDXContext				= std::add_pointer_t<ID3D11DeviceContext>;

	// Shader resources (buffer and textures)
	using LPDXResource				= std::add_pointer_t<ID3D11Resource>;
	using LPDXBuffer				= std::add_pointer_t<ID3D11Buffer>;
	using LPDXTexture2D				= std::add_pointer_t<ID3D11Texture2D>;
	using LPDXShaderResourceView	= std::add_pointer_t<ID3D11ShaderResourceView>;
	using LPDXRenderTargetView		= std::add_pointer_t<ID3D11RenderTargetView>;
	using LPDXDepthStencilView		= std::add_pointer_t<ID3D11DepthStencilView>;
	using LPDXUnorderedAccessView	= std::add_pointer_t<ID3D11UnorderedAccessView>;

	// Shaders
	using LPDXVertexShader			= std::add_pointer_t<ID3D11VertexShader>;
	using LPDXHullShader			= std::add_pointer_t<ID3D11HullShader>;
	using LPDXDomainShader			= std::add_pointer_t<ID3D11DomainShader>;
	using LPDXGeometryShader		= std::add_pointer_t<ID3D11GeometryShader>;
	using LPDXPixelShader			= std::add_pointer_t<ID3D11PixelShader>;
	using LPDXComputeShader			= std::add_pointer_t<ID3D11ComputeShader>;

	// States
	using LPDXBlendState			= std::add_pointer_t<ID3D11BlendState>;
	using LPDXDepthStencilState		= std::add_pointer_t<ID3D11DepthStencilState>;
	using LPDXRasterizerState		= std::add_pointer_t<ID3D11RasterizerState>;
	using LPDXSamplerState			= std::add_pointer_t<ID3D11SamplerState>;

	// Input assembler
	using LPDXInputLayout			= std::add_pointer_t<ID3D11InputLayout>;

	// Basic types
	using pbool						= std::add_pointer_t<bool>;
	using pchar						= std::add_pointer_t<char>;
	using pint						= std::add_pointer_t<int>;
	using pfloat					= std::add_pointer_t<float>;
	using pbyte						= std::add_pointer_t<byte>;
	using pint8						= std::add_pointer_t<int8_t>;
	using puint8					= std::add_pointer_t<uint8_t>;
	using puint						= std::add_pointer_t<uint32_t>;
	using lpvoid					= std::add_pointer_t<void>;
	using lpcvoid					= std::add_pointer_t<const void>;

	// Float vectors
	using lpfloat2					= std::add_pointer_t<DirectX::XMFLOAT2>;
	using lpfloat3					= std::add_pointer_t<DirectX::XMFLOAT3>;
	using lpfloat4					= std::add_pointer_t<DirectX::XMFLOAT4>;
	using lpfloat3x3				= std::add_pointer_t<DirectX::XMFLOAT3X3>;
	using lpfloat4x3				= std::add_pointer_t<DirectX::XMFLOAT4X3>;
	using lpfloat4x4				= std::add_pointer_t<DirectX::XMFLOAT4X4>;
	using lpcfloat2					= std::add_pointer_t<const DirectX::XMFLOAT2>;
	using lpcfloat3					= std::add_pointer_t<const DirectX::XMFLOAT3>;
	using lpcfloat4					= std::add_pointer_t<const DirectX::XMFLOAT4>;
	using lpcfloat3x3				= std::add_pointer_t<const DirectX::XMFLOAT3X3>;
	using lpcfloat4x3				= std::add_pointer_t<const DirectX::XMFLOAT4X3>;
	using lpcfloat4x4				= std::add_pointer_t<const DirectX::XMFLOAT4X4>;

	// Vectors and matrices
	using LPVECTOR					= std::add_pointer_t<DirectX::XMVECTOR>;
	using LPMATRIX					= std::add_pointer_t<DirectX::XMMATRIX>;
	using LPCVECTOR					= std::add_pointer_t<DirectX::FXMVECTOR>;
	using LPCMATRIX					= std::add_pointer_t<DirectX::FXMMATRIX>;

#ifdef _PACKED_VECTOR_
	using lphalf					= std::add_pointer_t<DirectX::PackedVector::HALF>;
	using lphalf2					= std::add_pointer_t<DirectX::PackedVector::XMHALF2>;
	using lphalf4					= std::add_pointer_t<DirectX::PackedVector::XMHALF4>;
	using lpchalf					= std::add_pointer_t<const DirectX::PackedVector::HALF>;
	using lpchalf2					= std::add_pointer_t<const DirectX::PackedVector::XMHALF2>;
	using lpchalf4					= std::add_pointer_t<const DirectX::PackedVector::XMHALF4>;
#endif

	//--------------------------------------------------------------------------------------
	// Vectors
	//--------------------------------------------------------------------------------------

	// DirectX types
	using vCPDXBuffer				= std::vector<CPDXBuffer>;
	using vCPDXTexture2D			= std::vector<CPDXTexture2D>;
	using vCPDXSRV					= std::vector<CPDXShaderResourceView>;
	using vCPDXUAV					= std::vector<CPDXUnorderedAccessView>;

	// Basic types
	using vbool						= std::vector<bool>;
	using vchar						= std::vector<char>;
	using vint						= std::vector<int>;
	using vfloat					= std::vector<float>;
	using vbyte						= std::vector<byte>;
	using vint8						= std::vector<int8_t>;
	using vuint8					= std::vector<uint8_t>;
	using vuint						= std::vector<uint32_t>;

	// Vector vectors
	using vvbool					= std::vector<vbool>;
	using vvchar					= std::vector<vchar>;
	using vvint						= std::vector<vint>;
	using vvfloat					= std::vector<vfloat>;
	using vvbyte					= std::vector<vbyte>;
	using vvint8					= std::vector<vint8>;
	using vvuint8					= std::vector<vuint8>;
	using vvuint					= std::vector<vuint>;

	// Integer vectors
	using vint2						= std::vector<DirectX::XMINT2>;
	using vint3						= std::vector<DirectX::XMINT3>;
	using vint4						= std::vector<DirectX::XMINT4>;
	using vuint2					= std::vector<DirectX::XMUINT2>;
	using vuint3					= std::vector<DirectX::XMUINT3>;
	using vuint4					= std::vector<DirectX::XMUINT4>;

	// Float vectors and matrices
	using vfloat2					= std::vector<DirectX::XMFLOAT2>;
	using vfloat3					= std::vector<DirectX::XMFLOAT3>;
	using vfloat4					= std::vector<DirectX::XMFLOAT4>;
	using vfloat3x3					= std::vector<DirectX::XMFLOAT3X3>;
	using vfloat4x3					= std::vector<DirectX::XMFLOAT4X3>;
	using vfloat4x4					= std::vector<DirectX::XMFLOAT4X4>;

	// Packed vectors
#ifdef _PACKED_VECTOR_
	using vchar2					= std::vector<DirectX::PackedVector::XMBYTE2>;
	using vchar4					= std::vector<DirectX::PackedVector::XMBYTE4>;
	using vbyte2					= std::vector<DirectX::PackedVector::XMUBYTE2>;
	using vbyte4					= std::vector<DirectX::PackedVector::XMUBYTE4>;
	using vhalf						= std::vector<DirectX::PackedVector::HALF>;
	using vhalf2					= std::vector<DirectX::PackedVector::XMHALF2>;
	using vhalf4					= std::vector<DirectX::PackedVector::XMHALF4>;
#endif

	//--------------------------------------------------------------------------------------
	// Concurrency tasks
	//--------------------------------------------------------------------------------------
	using TaskVecByte				= Concurrency::task<vbyte>;
	using TaskVoid					= Concurrency::task<void>;
	using TaskCPDXBlob				= Concurrency::task<CPDXBlob>;

	//--------------------------------------------------------------------------------------
	// Others
	//--------------------------------------------------------------------------------------
	using wstring64					= wchar_t[64];
}
