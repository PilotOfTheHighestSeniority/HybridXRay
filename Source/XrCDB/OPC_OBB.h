﻿///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains OBB-related code. (oriented bounding box)
 *	\file		IceOBB.h
 *	\author		Pierre Terdiman
 *	\date		January, 13, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __ICEOBB_H__
#define __ICEOBB_H__

class IndexedTriangle;
class LSS;

class MESHMERIZER_API OBB
{
public:
    //! Constructor
    inline_ OBB() {}
    //! Constructor
    inline_ OBB(const Point& center, const Point& extents, const Matrix3x3& rot): mCenter(center), mExtents(extents), mRot2(rot) {}
    //! Destructor
    inline_ ~OBB() {}

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Tests if a point is contained within the OBB.
     *	\param		p	[in] the world point to test
     *	\return		true if inside the OBB
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool         ContainsPoint(const Point& p) const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Builds an OBB from an AABB and a world transform.
     *	\param		aabb	[in] the aabb
     *	\param		mat		[in] the world transform
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void         Create(const AABB& aabb, const Matrix4x4& mat);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Recomputes the OBB after an arbitrary transform by a 4x4 matrix.
     *	\param		mtx		[in] the transform matrix
     *	\param		obb		[out] the transformed OBB
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ void Rotate(const Matrix4x4& mtx, OBB& obb) const
    {
        // The extents remain constant
        obb.mExtents = mExtents;
        // The center gets x-formed
        obb.mCenter  = mCenter * mtx;
        // Combine rotations
        obb.mRot2    = mRot2 * Matrix3x3(mtx);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Computes the obb planes.
     *	\param		planes	[out] 6 box planes
     *	\return		true if success
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool          ComputePlanes(Plane* planes) const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Computes the obb points.
     *	\param		pts	[out] 8 box points
     *	\return		true if success
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool          ComputePoints(Point* pts) const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Returns a list of indices used to draw the OBB.
     *	\return		48 indices for the list returned by ComputePoints()
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const udword* GetLineIndices() const;

    void          ComputeLSS(LSS& lss);

    Point         mCenter;    //!< B for Box
    Point         mExtents;   //!< B for Bounding
                              //				Matrix3x3		mRot;			//!< O for Oriented
    Matrix3x3     mRot2;      //!< O for Oriented

    // Orientation is stored in row-major format,
    // i.e. rows = eigen vectors of the covariance matrix
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Eigen analysis of a triangular mesh.
 *	\param		tris			[in] list of triangles
 *	\param		nbtris			[in] number of triangles
 *	\param		verts			[in] list of vertices
 *	\param		nbverts			[in] number of vertices
 *	\param		center			[out] center of mesh
 *	\param		eigenvalues		[out] eigen values
 *	\param		eigenvectors	[out] eigen vectors (stored in columns)
 *	\param		usehull			[in] true to use the convex hull
 *	\return		true if success
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FUNCTION MESHMERIZER_API bool ComputeSpread(const IndexedTriangle* tris, udword nbtris, const Point* verts, udword nbverts, Point& center, Point& eigenvalues, Matrix3x3& eigenvectors, bool usehull = false);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Computes an OBB for a triangular mesh.
 *	\param		tris	[in] list of triangles
 *	\param		nbtris	[in] number of triangles
 *	\param		verts	[in] list of vertices
 *	\param		nbverts	[in] number of vertices
 *	\param		obb		[out] the obb
 *	\param		usehull	[in] true to compute the OBB of the mesh's convex hull
 *	\return		true if success
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FUNCTION MESHMERIZER_API bool ComputeOBB(const IndexedTriangle* tris, udword nbtris, const Point* verts, udword nbverts, OBB& obb, bool usehull);

FUNCTION MESHMERIZER_API void OBBFromTriangle(const Point& p1, const Point& p2, const Point& p3, OBB& obb);

#endif   // __ICEOBB_H__
