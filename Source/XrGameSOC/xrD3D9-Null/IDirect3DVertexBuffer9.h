﻿

#ifdef __cplusplus
extern "C"
{
#endif

    class xrIDirect3DVertexBuffer9: public IDirect3DVertexBuffer9
    {
    protected:
        LONG              m_refCount;
        BYTE*             m_pBuffer;
        IDirect3DDevice9* m_pIDirect3DDevice9;

    public:
        xrIDirect3DVertexBuffer9(IDirect3DDevice9* pIDirect3DDevice9, UINT iLength, DWORD iUsage, DWORD iFVF, D3DPOOL iPool);
        /*** IUnknown methods ***/
        HRESULT         QueryInterface(REFIID riid, void** ppvObj);
        ULONG           AddRef();
        ULONG           Release();

        /*** IDirect3DResource9 methods ***/
        HRESULT         GetDevice(IDirect3DDevice9** ppDevice);
        HRESULT         SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags);
        HRESULT         GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData);
        HRESULT         FreePrivateData(REFGUID refguid);
        DWORD           SetPriority(DWORD PriorityNew);
        DWORD           GetPriority();
        void            PreLoad();
        D3DRESOURCETYPE GetType();
        HRESULT         Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags);
        HRESULT         Unlock();
        HRESULT         GetDesc(D3DVERTEXBUFFER_DESC* pDesc);

        //#ifdef D3D_DEBUG_INFO
        LPCWSTR         Name;
        UINT            Length;
        DWORD           Usage;
        DWORD           m_FVF;
        D3DPOOL         Pool;
        DWORD           Priority;
        UINT            LockCount;
        LPCWSTR         CreationCallStack;
        //#endif
    };

#ifdef __cplusplus
};
#endif
