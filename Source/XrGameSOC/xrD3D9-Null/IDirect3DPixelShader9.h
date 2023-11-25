﻿

#ifdef __cplusplus
extern "C"
{
#endif

    class xrIDirect3DPixelShader9: public IDirect3DPixelShader9
    {
    protected:
        LONG              m_refCount;
        IDirect3DDevice9* m_pIDirect3DDevice9;

    public:
        xrIDirect3DPixelShader9(IDirect3DDevice9* pIDirect3DDevice9);
        /*** IUnknown methods ***/
        HRESULT QueryInterface(REFIID riid, void** ppvObj);
        ULONG   AddRef();
        ULONG   Release();

        /*** IDirect3DVertexDeclaration9 methods ***/
        HRESULT GetDevice(IDirect3DDevice9** ppDevice);
        HRESULT GetFunction(void*, UINT* pSizeOfData);
    };

#ifdef __cplusplus
};
#endif
