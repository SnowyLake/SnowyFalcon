// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#define NANITE_SUBPIXEL_BITS								8
#define NANITE_SUBPIXEL_SAMPLES								(1 << NANITE_SUBPIXEL_BITS)
#define NANITE_SUBPIXEL_MASK								(NANITE_SUBPIXEL_SAMPLES - 1)
#define NANITE_SUBPIXEL_DILATE								0	// To correct for mismatch with HW rasterizer

#define NANITE_LATE_VSM_PAGE_TRANSLATION					1
#define NANITE_VSM_PAGE_TABLE_CACHE_DIM						8

#define NANITE_USE_UNCOMPRESSED_VERTEX_DATA					0

#define NANITE_MAX_STREAMING_REQUESTS						(256u * 1024u)
#define NANITE_MAX_CLUSTER_TRIANGLES_BITS					7
#define NANITE_MAX_CLUSTER_TRIANGLES						(1 << NANITE_MAX_CLUSTER_TRIANGLES_BITS)
#define NANITE_MAX_CLUSTER_TRIANGLES_MASK					((1 << NANITE_MAX_CLUSTER_TRIANGLES_BITS)) - 1
#define NANITE_MAX_CLUSTER_VERTICES_BITS					8
#define NANITE_MAX_CLUSTER_VERTICES							(1 << NANITE_MAX_CLUSTER_VERTICES_BITS)
#define NANITE_MAX_CLUSTER_VERTICES_MASK					((1 << NANITE_MAX_CLUSTER_VERTICES_BITS) - 1)

#define NANITE_MAX_CLUSTER_INDICES							(NANITE_MAX_CLUSTER_TRIANGLES * 3)
#define NANITE_MAX_UVS										4

#define NANITE_MAX_CLUSTER_MATERIALS						64

#define NANITE_USE_STRIP_INDICES							1

#define NANITE_ROOT_PAGE_GPU_SIZE_BITS						15
#define NANITE_ROOT_PAGE_GPU_SIZE							(1u << NANITE_ROOT_PAGE_GPU_SIZE_BITS)

// Adds frame counter dependent magic values to streaming requests to help verify their integrity.
#define NANITE_SANITY_CHECK_STREAMING_REQUESTS				0

#define NANITE_FIXUP_MAGIC									0x464Eu

#define NANITE_STREAMING_REQUEST_MAGIC_BITS					8
#define NANITE_STREAMING_REQUEST_MAGIC_MASK					((1 << NANITE_STREAMING_REQUEST_MAGIC_BITS) - 1)

#define NANITE_STREAMING_PAGE_GPU_SIZE_BITS					17
#define NANITE_STREAMING_PAGE_GPU_SIZE						(1u << NANITE_STREAMING_PAGE_GPU_SIZE_BITS)
#define NANITE_MAX_PAGE_DISK_SIZE							(NANITE_STREAMING_PAGE_GPU_SIZE * 2)

#define NANITE_MAX_CLUSTERS_PER_PAGE_BITS					8
#define NANITE_MAX_CLUSTERS_PER_PAGE_MASK					((1 << NANITE_MAX_CLUSTERS_PER_PAGE_BITS) - 1)
#define NANITE_MAX_CLUSTERS_PER_PAGE						( 1 << NANITE_MAX_CLUSTERS_PER_PAGE_BITS)
#define NANITE_MAX_CLUSTERS_PER_GROUP_BITS					9
#define NANITE_MAX_CLUSTERS_PER_GROUP_MASK					((1 << NANITE_MAX_CLUSTERS_PER_GROUP_BITS) - 1)
#define NANITE_MAX_CLUSTERS_PER_GROUP						((1 << NANITE_MAX_CLUSTERS_PER_GROUP_BITS) - 1)
#define NANITE_MAX_CLUSTERS_PER_GROUP_TARGET				128
#define NANITE_MAX_CLUSTER_HIERARCHY_DEPTH					14

#define NANITE_MAX_HIERACHY_CHILDREN_BITS					6
#define NANITE_MAX_HIERACHY_CHILDREN						(1 << NANITE_MAX_HIERACHY_CHILDREN_BITS)
#define NANITE_MAX_VIEWS_PER_CULL_RASTERIZE_PASS_BITS		12
#define NANITE_MAX_VIEWS_PER_CULL_RASTERIZE_PASS_MASK		((1 << NANITE_MAX_VIEWS_PER_CULL_RASTERIZE_PASS_BITS) - 1)
#define NANITE_MAX_VIEWS_PER_CULL_RASTERIZE_PASS			(1 << NANITE_MAX_VIEWS_PER_CULL_RASTERIZE_PASS_BITS)
#define NANITE_MAX_GPU_PAGES_BITS							16
#define NANITE_MAX_GPU_PAGES_MASK							((1 << NANITE_MAX_GPU_PAGES_BITS) - 1)
#define NANITE_MAX_GPU_PAGES								( 1 << NANITE_MAX_GPU_PAGES_BITS)
#define NANITE_MAX_INSTANCES_BITS							24
#define NANITE_MAX_INSTANCES								(1 << NANITE_MAX_INSTANCES_BITS)	

#define NANITE_MAX_NODES_PER_PRIMITIVE_BITS					16
#define NANITE_MAX_RESOURCE_PAGES_BITS						20
#define NANITE_MAX_RESOURCE_PAGES_MASK						((1 << NANITE_MAX_RESOURCE_PAGES_BITS) - 1)
#define NANITE_MAX_RESOURCE_PAGES							(1 << NANITE_MAX_RESOURCE_PAGES_BITS)
#define NANITE_MAX_GROUP_PARTS_BITS							3
#define NANITE_MAX_GROUP_PARTS_MASK							((1 << NANITE_MAX_GROUP_PARTS_BITS) - 1)
#define NANITE_MAX_GROUP_PARTS								(1 << NANITE_MAX_GROUP_PARTS_BITS)

#define NANITE_FILTER_FLAGS_NUM_BITS						(6u)
#define NANITE_IMPOSTER_INDEX_NUM_BITS						(32u - NANITE_FILTER_FLAGS_NUM_BITS)
#define NANITE_IMPOSTER_INDEX_MASK							((1u << NANITE_IMPOSTER_INDEX_NUM_BITS) - 1u)
#define NANITE_FILTER_FLAGS_MASK							(((1u << NANITE_FILTER_FLAGS_NUM_BITS) - 1u) << NANITE_IMPOSTER_INDEX_NUM_BITS)
#define INVALID_NANITE_IMPOSTER_INDEX						(0xFFFFFFFFu)

#define NANITE_IMPOSTERS_SUPPORTED							0

#define NANITE_MAX_BVH_NODE_FANOUT_BITS						2
#define NANITE_MAX_BVH_NODE_FANOUT_MASK						((1 << NANITE_MAX_BVH_NODE_FANOUT_BITS)-1)
#define NANITE_MAX_BVH_NODE_FANOUT							(1 << NANITE_MAX_BVH_NODE_FANOUT_BITS)
#define NANITE_BVH_NODE_ENABLE_MASK							((1 << NANITE_MAX_BVH_NODE_FANOUT)-1)

#define NANITE_PERSISTENT_CLUSTER_CULLING_GROUP_SIZE		64
#define NANITE_MAX_BVH_NODES_PER_GROUP						(NANITE_PERSISTENT_CLUSTER_CULLING_GROUP_SIZE / NANITE_MAX_BVH_NODE_FANOUT)

#define NANITE_NUM_STREAMING_PRIORITY_CATEGORY_BITS			2
#define NANITE_STREAMING_PRIORITY_CATEGORY_MASK				((1 << NANITE_NUM_STREAMING_PRIORITY_CATEGORY_BITS) - 1)
#define NANITE_MAX_PRIORITY_BEFORE_PARENTS					0xFFFFFFE0u

#define NANITE_VIEW_FLAG_HZBTEST							0x1
#define NANITE_VIEW_FLAG_NEAR_CLIP							0x2
#define NANITE_VIEW_FLAG_DISTANCE_CULL						0x4
#define NANITE_VIEW_FLAG_UNCACHED							0x8 // Indicates that the view does not support caching, used in VSM rendering to pipe everything to the dynamic pages and skip merging
#define NANITE_VIEW_FLAG_REVERSE_CULLING					0x10

#define NANITE_MAX_STATE_BUCKET_ID							((1 << 14) - 1)

#define NANITE_CLUSTER_FLAG_ROOT_LEAF						0x1		// Cluster is leaf when only root pages are streamed in
#define NANITE_CLUSTER_FLAG_STREAMING_LEAF					0x2		// Cluster is a leaf in the current streaming state
#define NANITE_CLUSTER_FLAG_FULL_LEAF						0x4		// Cluster is a leaf when fully streamed in
#define NANITE_CLUSTER_FLAG_ROOT_GROUP						0x8		// Cluster is in a group that is fully inside the root pages

#define NANITE_MAX_TRANSCODE_GROUPS_PER_PAGE				128

#define NANITE_NUM_PACKED_CLUSTER_FLOAT4S					7
#define NANITE_GPU_PAGE_HEADER_SIZE							16

#define NANITE_MAX_POSITION_QUANTIZATION_BITS				21	// (21*3 = 63) < 64
#define NANITE_POSITION_PRECISION_BITS						5
#define NANITE_MIN_POSITION_PRECISION						-8
#define NANITE_MAX_POSITION_PRECISION						23

#define NANITE_MAX_NORMAL_QUANTIZATION_BITS					15
#define NANITE_MAX_TANGENT_QUANTIZATION_BITS				12
#define NANITE_MAX_TEXCOORD_QUANTIZATION_BITS				15
#define NANITE_MAX_COLOR_QUANTIZATION_BITS					8

#define NANITE_RAY_TRACING_NODE_DATA_SIZE_IN_BYTES			80

#define NANITE_NUM_CULLING_FLAG_BITS						4
#define NANITE_CULLING_FLAG_TEST_LOD						0x1
#define NANITE_CULLING_FLAG_USE_HW							0x2
#define NANITE_CULLING_FLAG_FROM_DISOCCLUDED_INSTANCE		0x4
#define NANITE_CULLING_FLAG_ENABLE_WPO						0x8

#define NANITE_CULLING_TYPE_NODES							0
#define NANITE_CULLING_TYPE_CLUSTERS						1
#define NANITE_CULLING_TYPE_PERSISTENT_NODES_AND_CLUSTERS	2

#define NANITE_VERTEX_COLOR_MODE_WHITE						0
#define NANITE_VERTEX_COLOR_MODE_CONSTANT					1
#define NANITE_VERTEX_COLOR_MODE_VARIABLE					2

#define NANITE_PAGE_FLAG_RELATIVE_ENCODING					0x1

#define NANITE_INVALID_PERSISTENT_HASH						0

#define NANITE_RESOURCE_FLAG_HAS_VERTEX_COLOR				0x1
#define NANITE_RESOURCE_FLAG_HAS_IMPOSTER					0x2
#define NANITE_RESOURCE_FLAG_STREAMING_DATA_IN_DDC			0x4
#define NANITE_RESOURCE_FLAG_FORCE_ENABLED					0x8

#define NANITE_RENDER_FLAG_DISABLE_PROGRAMMABLE				0x1
#define NANITE_RENDER_FLAG_FORCE_HW_RASTER					0x2
#define NANITE_RENDER_FLAG_PRIMITIVE_SHADER					0x4
#define NANITE_RENDER_FLAG_MESH_SHADER						0x8
#define NANITE_RENDER_FLAG_OUTPUT_STREAMING_REQUESTS		0x10
#define NANITE_RENDER_FLAG_IS_SCENE_CAPTURE					0x20
#define NANITE_RENDER_FLAG_IS_REFLECTION_CAPTURE			0x40
#define NANITE_RENDER_FLAG_IS_GAME_VIEW						0x80
#define NANITE_RENDER_FLAG_GAME_SHOW_FLAG_ENABLED			0x100
#define NANITE_RENDER_FLAG_EDITOR_SHOW_FLAG_ENABLED			0x200
#define NANITE_RENDER_FLAG_IS_LUMEN_CAPTURE					0x400
#define NANITE_RENDER_FLAG_ADD_CLUSTER_OFFSET				0x800
#define NANITE_RENDER_FLAG_HAS_PREV_DRAW_DATA				0x1000
#define NANITE_RENDER_FLAG_INVALIDATE_VSM_ON_LOD_DELTA		0x2000

#define NANITE_MATERIAL_FLAG_WORLD_POSITION_OFFSET			0x1
#define NANITE_MATERIAL_FLAG_PIXEL_DEPTH_OFFSET				0x2
#define NANITE_MATERIAL_FLAG_PIXEL_DISCARD					0x4
#define NANITE_MATERIAL_FLAG_DISPLACEMENT					0x8
#define NANITE_MATERIAL_FLAG_SPLINE_MESH					0x10

#define NANITE_MATERIAL_VERTEX_PROGRAMMABLE_FLAGS			(NANITE_MATERIAL_FLAG_WORLD_POSITION_OFFSET | NANITE_MATERIAL_FLAG_DISPLACEMENT)
#define NANITE_MATERIAL_PIXEL_PROGRAMMABLE_FLAGS			(NANITE_MATERIAL_FLAG_PIXEL_DEPTH_OFFSET | NANITE_MATERIAL_FLAG_PIXEL_DISCARD)

// Only available with the DEBUG_FLAGS permutation active.
// Default value (no debug) is 0
#define NANITE_DEBUG_FLAG_WRITE_STATS						0x1
#define NANITE_DEBUG_FLAG_DISABLE_CULL_HZB					0x2
#define NANITE_DEBUG_FLAG_DISABLE_CULL_FRUSTUM				0x4
#define NANITE_DEBUG_FLAG_DISABLE_CULL_DRAW_DISTANCE		0x8
#define NANITE_DEBUG_FLAG_DISABLE_CULL_GLOBAL_CLIP_PLANE	0x10
#define NANITE_DEBUG_FLAG_DISABLE_WPO_DISABLE_DISTANCE		0x20
#define NANITE_DEBUG_FLAG_DRAW_ONLY_VSM_INVALIDATING		0x40
#define NANITE_DEBUG_FLAG_DRAW_ONLY_ROOT_DATA				0x80

#define NANITE_RASTER_BIN_COUNT			0
#define NANITE_RASTER_BIN_RESERVE		1
#define NANITE_RASTER_BIN_SCATTER		2
#define NANITE_RASTER_BIN_FINALIZE		3

#define NANITE_SHADING_BIN_COUNT		0
#define NANITE_SHADING_BIN_RESERVE		1
#define NANITE_SHADING_BIN_SCATTER		2

// 3x for SW, 1x for padding, 4x for HW
#define NANITE_RASTERIZER_ARG_COUNT 8u

// Debug Visualization Modes
#define NANITE_VISUALIZE_OVERVIEW							0u
#define NANITE_VISUALIZE_TRIANGLES							1u
#define NANITE_VISUALIZE_CLUSTERS							2u
#define NANITE_VISUALIZE_PRIMITIVES							3u
#define NANITE_VISUALIZE_INSTANCES							4u
#define NANITE_VISUALIZE_GROUPS								5u
#define NANITE_VISUALIZE_PAGES								6u
#define NANITE_VISUALIZE_OVERDRAW							7u
#define NANITE_VISUALIZE_RASTER_MODE						8u
#define NANITE_VISUALIZE_RASTER_BINS						9u
#define NANITE_VISUALIZE_SHADING_BINS						10u
#define NANITE_VISUALIZE_SCENE_Z_MIN						11u
#define NANITE_VISUALIZE_SCENE_Z_MAX						12u
#define NANITE_VISUALIZE_SCENE_Z_DELTA						13u
#define NANITE_VISUALIZE_SCENE_Z_DECODED					14u
#define NANITE_VISUALIZE_MATERIAL_Z_MIN						15u
#define NANITE_VISUALIZE_MATERIAL_Z_MAX						16u
#define NANITE_VISUALIZE_MATERIAL_Z_DELTA					17u
#define NANITE_VISUALIZE_MATERIAL_Z_DECODED					18u
#define NANITE_VISUALIZE_MATERIAL_COUNT						19u
#define NANITE_VISUALIZE_MATERIAL_MODE						20u
#define NANITE_VISUALIZE_MATERIAL_INDEX						21u
#define NANITE_VISUALIZE_MATERIAL_DEPTH						22u
#define NANITE_VISUALIZE_HIT_PROXY_DEPTH					23u
#define NANITE_VISUALIZE_NANITE_MASK						24u
#define NANITE_VISUALIZE_LIGHTMAP_UVS						25u
#define NANITE_VISUALIZE_LIGHTMAP_UV_INDEX					26u
#define NANITE_VISUALIZE_LIGHTMAP_DATA_INDEX				27u
#define NANITE_VISUALIZE_HIERARCHY_OFFSET					28u
#define NANITE_VISUALIZE_POSITION_BITS						29u
#define NANITE_VISUALIZE_VSM_STATIC_CACHING					30u
#define NANITE_VISUALIZE_EVALUATE_WORLD_POSITION_OFFSET		31u
#define NANITE_VISUALIZE_PICKING							32u
#define NANITE_VISUALIZE_SHADING_WRITE_MASK					33u

#define NANITE_PICKING_DOMAIN_TRIANGLE		0
#define NANITE_PICKING_DOMAIN_CLUSTER		1
#define NANITE_PICKING_DOMAIN_INSTANCE		2
#define NANITE_PICKING_DOMAIN_PRIMITIVE		3

#if defined(__cplusplus)
#define UINT_TYPE unsigned int
#define  INT_TYPE int
#define INLINE_ATTR inline
#else
#define UINT_TYPE uint
#define  INT_TYPE int
#define INLINE_ATTR 
#endif

struct FNaniteMaterialFlags
{
	bool bWorldPositionOffset;
	bool bPixelDepthOffset;
	bool bPixelDiscard;
	bool bDisplacement;
	bool bSplineMesh;

	bool bVertexProgrammable;
	bool bPixelProgrammable;
};

INLINE_ATTR FNaniteMaterialFlags UnpackNaniteMaterialFlags(UINT_TYPE Packed)
{
	FNaniteMaterialFlags MaterialFlags;
	MaterialFlags.bWorldPositionOffset = (Packed & NANITE_MATERIAL_FLAG_WORLD_POSITION_OFFSET) != 0u;
	MaterialFlags.bPixelDepthOffset = (Packed & NANITE_MATERIAL_FLAG_PIXEL_DEPTH_OFFSET) != 0u;
	MaterialFlags.bPixelDiscard = (Packed & NANITE_MATERIAL_FLAG_PIXEL_DISCARD) != 0u;
	MaterialFlags.bDisplacement = (Packed & NANITE_MATERIAL_FLAG_DISPLACEMENT) != 0u;
	MaterialFlags.bSplineMesh = (Packed & NANITE_MATERIAL_FLAG_SPLINE_MESH) != 0u;
	MaterialFlags.bVertexProgrammable = (Packed & NANITE_MATERIAL_VERTEX_PROGRAMMABLE_FLAGS) != 0u;
	MaterialFlags.bPixelProgrammable = (Packed & NANITE_MATERIAL_PIXEL_PROGRAMMABLE_FLAGS) != 0u;
	return MaterialFlags;
}

INLINE_ATTR bool IsNaniteMaterialVertexProgrammable(FNaniteMaterialFlags MaterialFlags)
{
	return MaterialFlags.bWorldPositionOffset || MaterialFlags.bDisplacement;
}

INLINE_ATTR bool IsNaniteMaterialPixelProgrammable(FNaniteMaterialFlags MaterialFlags)
{
	return MaterialFlags.bPixelDepthOffset || MaterialFlags.bPixelDiscard;
}

INLINE_ATTR bool IsNaniteMaterialProgrammable(FNaniteMaterialFlags MaterialFlags)
{
	return IsNaniteMaterialVertexProgrammable(MaterialFlags) || IsNaniteMaterialPixelProgrammable(MaterialFlags);
}

INLINE_ATTR UINT_TYPE PackNaniteMaterialBitFlags(FNaniteMaterialFlags Flags)
{
	UINT_TYPE MaterialBitFlags = 0x00000000u;

	if (Flags.bPixelDiscard)
	{
		MaterialBitFlags |= NANITE_MATERIAL_FLAG_PIXEL_DISCARD;
	}

	if (Flags.bPixelDepthOffset)
	{
		MaterialBitFlags |= NANITE_MATERIAL_FLAG_PIXEL_DEPTH_OFFSET;
	}

	if (Flags.bWorldPositionOffset)
	{
		MaterialBitFlags |= NANITE_MATERIAL_FLAG_WORLD_POSITION_OFFSET;
	}

	if (Flags.bDisplacement)
	{
		MaterialBitFlags |= NANITE_MATERIAL_FLAG_DISPLACEMENT;
	}

	if (Flags.bSplineMesh)
	{
		MaterialBitFlags |= NANITE_MATERIAL_FLAG_SPLINE_MESH;
	}

	return MaterialBitFlags;
}

struct FNaniteStats
{
	UINT_TYPE NumTris;
	UINT_TYPE NumVerts;
	UINT_TYPE NumViews;
	UINT_TYPE NumMainInstancesPreCull;
	UINT_TYPE NumMainInstancesPostCull;
	UINT_TYPE NumMainVisitedNodes;
	UINT_TYPE NumMainCandidateClusters;
	UINT_TYPE NumPostInstancesPreCull;
	UINT_TYPE NumPostInstancesPostCull;
	UINT_TYPE NumPostVisitedNodes;
	UINT_TYPE NumPostCandidateClusters;
	UINT_TYPE NumLargePageRectClusters;
	UINT_TYPE NumPrimaryViews;
	UINT_TYPE NumTotalViews;
	UINT_TYPE NumTotalRasterBins;
	UINT_TYPE NumEmptyRasterBins;
	UINT_TYPE NumTotalShadingBins;
	UINT_TYPE NumEmptyShadingBins;
	UINT_TYPE NumShadedQuads;
	UINT_TYPE NumShadedPixels;
	UINT_TYPE NumHelperLanes;
	UINT_TYPE NumMainPassIndirections;
	UINT_TYPE NumPostPassIndirections;
	UINT_TYPE NumMainHierarchyCellsPreCull;
	UINT_TYPE NumPostHierarchyCellsPreCull;
};

struct FNanitePickingFeedback
{
	UINT_TYPE PixelX;
	UINT_TYPE PixelY;
	UINT_TYPE PrimitiveId;
	UINT_TYPE InstanceId;

	UINT_TYPE PersistentIndex;
	UINT_TYPE ClusterIndex;
	UINT_TYPE GroupIndex;
	UINT_TYPE PageIndex;

	UINT_TYPE TriangleIndex;
	UINT_TYPE DepthInt;
	UINT_TYPE RasterMode;
	UINT_TYPE RasterBin;

	UINT_TYPE ShadingBin;
	UINT_TYPE MaterialIndex;
	UINT_TYPE MaterialDepthId;
	UINT_TYPE MaterialCount;

	UINT_TYPE MaterialMode;
	UINT_TYPE HierarchyOffset;
	UINT_TYPE RuntimeResourceID;
	UINT_TYPE LegacyShadingId;
};

struct FNaniteRasterBinMeta
{
	UINT_TYPE BinSWCount;
	UINT_TYPE BinHWCount;
	UINT_TYPE ClusterOffset;
	UINT_TYPE MaterialFlags;

	float MinMaterialDisplacement;
	float MaxMaterialDisplacement;
};

struct FNaniteShadingBinMeta
{
	// Quad count shaded by bin
	UINT_TYPE QuadCount;

	// Pixel count shaded by bin
	UINT_TYPE PixelCount;

	// Quad/pixel coord range start
	UINT_TYPE RangeStart;

	// 0:23 Material bit flags, 24:31 Bound Target Mask
	UINT_TYPE MaterialFlags;
};

struct FNaniteShadingBinStats
{
	UINT_TYPE TotalQuadCount;
	UINT_TYPE TotalPixelCount;
	UINT_TYPE TotalHelperCount;
};

#undef  INT_TYPE
#undef UINT_TYPE
#undef INLINE_ATTR
