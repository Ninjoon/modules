#include "registerttkfilters.h"

#include "ivw_ttkarrayeditor.h"
#include "ivw_ttkbarycentricsubdivision.h"
#include "ivw_ttkblockaggregator.h"
#include "ivw_ttkcinemaimaging.h"
#include "ivw_ttkcinemaproductreader.h"
#include "ivw_ttkcinemaquery.h"
#include "ivw_ttkcinemareader.h"
#include "ivw_ttkcinemawriter.h"
#include "ivw_ttkclusteringmetrics.h"
#include "ivw_ttkcomponentsize.h"
#include "ivw_ttkconnectedcomponents.h"
#include "ivw_ttkcontinuousscatterplot.h"
#include "ivw_ttkcontouraroundpoint.h"
#include "ivw_ttkcontourtree.h"
#include "ivw_ttkdatasetinterpolator.h"
#include "ivw_ttkdatasettotable.h"
#include "ivw_ttkdepthimagebasedgeometryapproximation.h"
#include "ivw_ttkdimensionreduction.h"
#include "ivw_ttkdiscretegradient.h"
#include "ivw_ttkdistancefield.h"
#include "ivw_ttkdistancematrixdistortion.h"
#include "ivw_ttkeigenfield.h"
#include "ivw_ttkendfor.h"
#include "ivw_ttkfiber.h"
#include "ivw_ttkfibersurface.h"
#include "ivw_ttkflattenmultiblock.h"
#include "ivw_ttkforeach.h"
#include "ivw_ttkgaussianpointcloud.h"
#include "ivw_ttkgeometrysmoother.h"
#include "ivw_ttkgridlayout.h"
#include "ivw_ttkharmonicfield.h"
#include "ivw_ttkhelloworld.h"
#include "ivw_ttkicosphere.h"
#include "ivw_ttkicospherefromobject.h"
#include "ivw_ttkicospheresfrompoints.h"
#include "ivw_ttkidentifierrandomizer.h"
#include "ivw_ttkidentifiers.h"
#include "ivw_ttkidentifybyscalarfield.h"
#include "ivw_ttkimportembeddingfromtable.h"
#include "ivw_ttkintegrallines.h"
#include "ivw_ttkjacobiset.h"
#include "ivw_ttkldistance.h"
#include "ivw_ttkldistancematrix.h"
#include "ivw_ttkmandatorycriticalpoints.h"
#include "ivw_ttkmanifoldcheck.h"
#include "ivw_ttkmarchingtetrahedra.h"
#include "ivw_ttkmatrixtoheatmap.h"
#include "ivw_ttkmergeblocktables.h"
#include "ivw_ttkmergetree.h"
#include "ivw_ttkmergetreeprincipalgeodesics.h"
#include "ivw_ttkmergetreeprincipalgeodesicsdecoding.h"
#include "ivw_ttkmergetreetemporalreduction.h"
#include "ivw_ttkmergetreetemporalreductiondecoding.h"
#include "ivw_ttkmeshgraph.h"
#include "ivw_ttkmeshsubdivision.h"
#include "ivw_ttkmetricdistortion.h"
#include "ivw_ttkmorphologicaloperators.h"
#include "ivw_ttkmorsesmalecomplex.h"
#include "ivw_ttkmorsesmalequadrangulation.h"
#include "ivw_ttkobjwriter.h"
#include "ivw_ttkoffreader.h"
#include "ivw_ttkoffwriter.h"
#include "ivw_ttkpathcompression.h"
#include "ivw_ttkperiodicghostsgeneration.h"
#include "ivw_ttkpersistencecurve.h"
#include "ivw_ttkpersistencediagram.h"
#include "ivw_ttkpersistencediagramapproximation.h"
#include "ivw_ttkplanargraphlayout.h"
#include "ivw_ttkpointdataconverter.h"
#include "ivw_ttkpointdataselector.h"
#include "ivw_ttkpointmerger.h"
#include "ivw_ttkpointsettocurve.h"
#include "ivw_ttkpointsettosurface.h"
#include "ivw_ttkprojectionfromfield.h"
#include "ivw_ttkquadrangulationsubdivision.h"
#include "ivw_ttkrangepolygon.h"
#include "ivw_ttkreebgraph.h"
#include "ivw_ttkreebspace.h"
#include "ivw_ttkripscomplex.h"
#include "ivw_ttkscalarfieldcriticalpoints.h"
#include "ivw_ttkscalarfieldnormalizer.h"
#include "ivw_ttkscalarfieldsmoother.h"
#include "ivw_ttkspherefrompoint.h"
#include "ivw_ttkstablemanifoldpersistence.h"
#include "ivw_ttkstringarrayconverter.h"
#include "ivw_ttksurfacegeometrysmoother.h"
#include "ivw_ttktabledataselector.h"
#include "ivw_ttktabledistancematrix.h"
#include "ivw_ttktexturemapfromfield.h"
#include "ivw_ttktopologicalcompression.h"
#include "ivw_ttktopologicalcompressionreader.h"
#include "ivw_ttktopologicalcompressionwriter.h"
#include "ivw_ttktopologicalsimplification.h"
#include "ivw_ttktopologicalsimplificationbypersistence.h"
#include "ivw_ttktrackingfromoverlap.h"
#include "ivw_ttktriangulationmanager.h"
#include "ivw_ttktriangulationreader.h"
#include "ivw_ttktriangulationrequest.h"
#include "ivw_ttktriangulationwriter.h"
#include "ivw_ttkuncertaindataestimator.h"
#include "ivw_ttkwebsocketio.h"
#include "ivw_vtkaggregatedatasetfilter.h"
#include "ivw_vtkangularperiodicfilter.h"
#include "ivw_vtkappendarclength.h"
#include "ivw_vtkappenddatasets.h"
#include "ivw_vtkappendpolydata.h"
#include "ivw_vtkblockidscalars.h"
#include "ivw_vtkbrownianpoints.h"
#include "ivw_vtkcellcenters.h"
#include "ivw_vtkcellderivatives.h"
#include "ivw_vtkcellvalidator.h"
#include "ivw_vtkcleanpolydata.h"
#include "ivw_vtkcompositecutter.h"
#include "ivw_vtkcomputequartiles.h"
#include "ivw_vtkconnectivityfilter.h"
#include "ivw_vtkcontourfilter.h"
#include "ivw_vtkcountfaces.h"
#include "ivw_vtkcountvertices.h"
#include "ivw_vtkcurvatures.h"
#include "ivw_vtkdatasetregionsurfacefilter.h"
#include "ivw_vtkdatasetsurfacefilter.h"
#include "ivw_vtkdatasettrianglefilter.h"
#include "ivw_vtkdecimatepolylinefilter.h"
#include "ivw_vtkdecimatepro.h"
#include "ivw_vtkdelaunay2d.h"
#include "ivw_vtkdelaunay3d.h"
#include "ivw_vtkdistributeddatafilter.h"
#include "ivw_vtkelevationfilter.h"
#include "ivw_vtkevenlyspacedstreamlines2d.h"
#include "ivw_vtkextractblock.h"
#include "ivw_vtkextractcthpart.h"
#include "ivw_vtkextractdatasets.h"
#include "ivw_vtkextractedges.h"
#include "ivw_vtkextractenclosedpoints.h"
#include "ivw_vtkextractgeometry.h"
#include "ivw_vtkextractlevel.h"
#include "ivw_vtkextracttimesteps.h"
#include "ivw_vtkfeatureedges.h"
#include "ivw_vtkforcetime.h"
#include "ivw_vtkgaussiansplatter.h"
#include "ivw_vtkgenericclip.h"
#include "ivw_vtkgenericcontourfilter.h"
#include "ivw_vtkgenericcutter.h"
#include "ivw_vtkgenericdatasettessellator.h"
#include "ivw_vtkgenericgeometryfilter.h"
#include "ivw_vtkgenericoutlinefilter.h"
#include "ivw_vtkgenericstreamtracer.h"
#include "ivw_vtkgradientfilter.h"
#include "ivw_vtkhypertreegridaxisclip.h"
#include "ivw_vtkhypertreegridaxiscut.h"
#include "ivw_vtkhypertreegridaxisreflection.h"
#include "ivw_vtkhypertreegridcellcenters.h"
#include "ivw_vtkhypertreegridcontour.h"
#include "ivw_vtkhypertreegriddepthlimiter.h"
#include "ivw_vtkhypertreegridgeometry.h"
#include "ivw_vtkhypertreegridplanecutter.h"
#include "ivw_vtkhypertreegridthreshold.h"
#include "ivw_vtkhypertreegridtodualgrid.h"
#include "ivw_vtkhypertreegridtounstructuredgrid.h"
#include "ivw_vtkidfilter.h"
#include "ivw_vtkimageclip.h"
#include "ivw_vtkimagedatatopointset.h"
#include "ivw_vtkimagedatatouniformgrid.h"
#include "ivw_vtkimagegradient.h"
#include "ivw_vtkimagegradientmagnitude.h"
#include "ivw_vtkimagemaptocolors.h"
#include "ivw_vtkimagemedian3d.h"
#include "ivw_vtkimageshrink3d.h"
#include "ivw_vtkimagetoamr.h"
#include "ivw_vtkintegrateattributes.h"
#include "ivw_vtklinearsubdivisionfilter.h"
#include "ivw_vtkloopsubdivisionfilter.h"
#include "ivw_vtkmergearrays.h"
#include "ivw_vtkmeshquality.h"
#include "ivw_vtkmoleculeappend.h"
#include "ivw_vtkmoleculetolinesfilter.h"
#include "ivw_vtkmultiblockdatagroupfilter.h"
#include "ivw_vtkoverlappingamrlevelidscalars.h"
#include "ivw_vtkpcelldatatopointdata.h"
#include "ivw_vtkpextractdataarraysovertime.h"
#include "ivw_vtkpextractexodusglobaltemporalvariables.h"
#include "ivw_vtkpextractselectedarraysovertime.h"
#include "ivw_vtkpmaskpoints.h"
#include "ivw_vtkpoutlinecornerfilter.h"
#include "ivw_vtkpoutlinefilter.h"
#include "ivw_vtkppolydatanormals.h"
#include "ivw_vtkpprobefilter.h"
#include "ivw_vtkpreflectionfilter.h"
#include "ivw_vtkpresamplefilter.h"
#include "ivw_vtkparticlepathfilter.h"
#include "ivw_vtkparticletracer.h"
#include "ivw_vtkpassarrays.h"
#include "ivw_vtkpassthrough.h"
#include "ivw_vtkplanecutter.h"
#include "ivw_vtkpointdatatocelldata.h"
#include "ivw_vtkpointsettomoleculefilter.h"
#include "ivw_vtkprocessidscalars.h"
#include "ivw_vtkquadraturepointinterpolator.h"
#include "ivw_vtkquadraturepointsgenerator.h"
#include "ivw_vtkquadratureschemedictionarygenerator.h"
#include "ivw_vtkquadricclustering.h"
#include "ivw_vtkrtxmlpolydatareader.h"
#include "ivw_vtkrandomattributegenerator.h"
#include "ivw_vtkrectilineargridgeometryfilter.h"
#include "ivw_vtkrectilineargridtopointset.h"
#include "ivw_vtkremoveghosts.h"
#include "ivw_vtkresampletoimage.h"
#include "ivw_vtkresamplewithdataset.h"
#include "ivw_vtkribbonfilter.h"
#include "ivw_vtkrotationalextrusionfilter.h"
#include "ivw_vtkshrinkfilter.h"
#include "ivw_vtksimplebondperceiver.h"
#include "ivw_vtksmoothpolydatafilter.h"
#include "ivw_vtkstreaklinefilter.h"
#include "ivw_vtkstreamtracer.h"
#include "ivw_vtkstripper.h"
#include "ivw_vtkstructuredgridoutlinefilter.h"
#include "ivw_vtksynchronizetimefilter.h"
#include "ivw_vtktablefft.h"
#include "ivw_vtktabletopolydata.h"
#include "ivw_vtktabletostructuredgrid.h"
#include "ivw_vtktemporalarrayoperatorfilter.h"
#include "ivw_vtktemporaldatasetcache.h"
#include "ivw_vtktemporalinterpolator.h"
#include "ivw_vtktemporalpathlinefilter.h"
#include "ivw_vtktemporalshiftscale.h"
#include "ivw_vtktemporalsnaptotimestep.h"
#include "ivw_vtktemporalstatistics.h"
#include "ivw_vtktensorglyph.h"
#include "ivw_vtktessellatorfilter.h"
#include "ivw_vtktexturemaptocylinder.h"
#include "ivw_vtktexturemaptoplane.h"
#include "ivw_vtktexturemaptosphere.h"
#include "ivw_vtkthreshold.h"
#include "ivw_vtktransformfilter.h"
#include "ivw_vtktrianglefilter.h"
#include "ivw_vtktubefilter.h"
#include "ivw_vtkunstructuredgridghostcellsgenerator.h"
#include "ivw_vtkwarpscalar.h"
#include "ivw_vtkwarpvector.h"
#include "ivw_vtkxmldataobjectwriter.h"
#include "ivw_vtkxmlhierarchicalboxdatareader.h"
#include "ivw_vtkxmlhypertreegridreader.h"
#include "ivw_vtkxmlimagedatareader.h"
#include "ivw_vtkxmlimagedatawriter.h"
#include "ivw_vtkxmlmultiblockdatareader.h"
#include "ivw_vtkxmlphypertreegridreader.h"
#include "ivw_vtkxmlpimagedatareader.h"
#include "ivw_vtkxmlppolydatareader.h"
#include "ivw_vtkxmlprectilineargridreader.h"
#include "ivw_vtkxmlpstructuredgridreader.h"
#include "ivw_vtkxmlptablereader.h"
#include "ivw_vtkxmlpunstructuredgridreader.h"
#include "ivw_vtkxmlpartitioneddatasetcollectionreader.h"
#include "ivw_vtkxmlpartitioneddatasetreader.h"
#include "ivw_vtkxmlpolydatareader.h"
#include "ivw_vtkxmlrectilineargridreader.h"
#include "ivw_vtkxmlstructuredgridreader.h"
#include "ivw_vtkxmltablereader.h"
#include "ivw_vtkxmluniformgridamrreader.h"
#include "ivw_vtkxmlunstructuredgridreader.h"
#include "ivw_vtkyoungsmaterialinterface.h"

namespace inviwo {
namespace ttkwrapper {

void registerTTKFilters(InviwoModule* module) {
    registerttkArrayEditor(module);
    registerttkBarycentricSubdivision(module);
    registerttkBlockAggregator(module);
    registerttkCinemaImaging(module);
    registerttkCinemaProductReader(module);
    registerttkCinemaQuery(module);
    registerttkCinemaReader(module);
    registerttkCinemaWriter(module);
    registerttkClusteringMetrics(module);
    registerttkComponentSize(module);
    registerttkConnectedComponents(module);
    registerttkContinuousScatterPlot(module);
    registerttkContourAroundPoint(module);
    registerttkContourTree(module);
    registerttkDataSetInterpolator(module);
    registerttkDataSetToTable(module);
    registerttkDepthImageBasedGeometryApproximation(module);
    registerttkDimensionReduction(module);
    registerttkDiscreteGradient(module);
    registerttkDistanceField(module);
    registerttkDistanceMatrixDistortion(module);
    registerttkEigenField(module);
    registerttkEndFor(module);
    registerttkFiber(module);
    registerttkFiberSurface(module);
    registerttkFlattenMultiBlock(module);
    registerttkForEach(module);
    registerttkGaussianPointCloud(module);
    registerttkGeometrySmoother(module);
    registerttkGridLayout(module);
    registerttkHarmonicField(module);
    registerttkHelloWorld(module);
    registerttkIcosphere(module);
    registerttkIcosphereFromObject(module);
    registerttkIcospheresFromPoints(module);
    registerttkIdentifierRandomizer(module);
    registerttkIdentifiers(module);
    registerttkIdentifyByScalarField(module);
    registerttkImportEmbeddingFromTable(module);
    registerttkIntegralLines(module);
    registerttkJacobiSet(module);
    registerttkLDistance(module);
    registerttkLDistanceMatrix(module);
    registerttkMandatoryCriticalPoints(module);
    registerttkManifoldCheck(module);
    registerttkMarchingTetrahedra(module);
    registerttkMatrixToHeatMap(module);
    registerttkMergeBlockTables(module);
    registerttkMergeTree(module);
    registerttkMergeTreePrincipalGeodesics(module);
    registerttkMergeTreePrincipalGeodesicsDecoding(module);
    registerttkMergeTreeTemporalReduction(module);
    registerttkMergeTreeTemporalReductionDecoding(module);
    registerttkMeshGraph(module);
    registerttkMeshSubdivision(module);
    registerttkMetricDistortion(module);
    registerttkMorphologicalOperators(module);
    registerttkMorseSmaleComplex(module);
    registerttkMorseSmaleQuadrangulation(module);
    registerttkOBJWriter(module);
    registerttkOFFReader(module);
    registerttkOFFWriter(module);
    registerttkPathCompression(module);
    registerttkPeriodicGhostsGeneration(module);
    registerttkPersistenceCurve(module);
    registerttkPersistenceDiagram(module);
    registerttkPersistenceDiagramApproximation(module);
    registerttkPlanarGraphLayout(module);
    registerttkPointDataConverter(module);
    registerttkPointDataSelector(module);
    registerttkPointMerger(module);
    registerttkPointSetToCurve(module);
    registerttkPointSetToSurface(module);
    registerttkProjectionFromField(module);
    registerttkQuadrangulationSubdivision(module);
    registerttkRangePolygon(module);
    registerttkReebGraph(module);
    registerttkReebSpace(module);
    registerttkRipsComplex(module);
    registerttkScalarFieldCriticalPoints(module);
    registerttkScalarFieldNormalizer(module);
    registerttkScalarFieldSmoother(module);
    registerttkSphereFromPoint(module);
    registerttkStableManifoldPersistence(module);
    registerttkStringArrayConverter(module);
    registerttkSurfaceGeometrySmoother(module);
    registerttkTableDataSelector(module);
    registerttkTableDistanceMatrix(module);
    registerttkTextureMapFromField(module);
    registerttkTopologicalCompression(module);
    registerttkTopologicalCompressionReader(module);
    registerttkTopologicalCompressionWriter(module);
    registerttkTopologicalSimplification(module);
    registerttkTopologicalSimplificationByPersistence(module);
    registerttkTrackingFromOverlap(module);
    registerttkTriangulationManager(module);
    registerttkTriangulationReader(module);
    registerttkTriangulationRequest(module);
    registerttkTriangulationWriter(module);
    registerttkUncertainDataEstimator(module);
    registerttkWebSocketIO(module);
    registervtkAggregateDataSetFilter(module);
    registervtkAngularPeriodicFilter(module);
    registervtkAppendArcLength(module);
    registervtkAppendDataSets(module);
    registervtkAppendPolyData(module);
    registervtkBlockIdScalars(module);
    registervtkBrownianPoints(module);
    registervtkCellCenters(module);
    registervtkCellDerivatives(module);
    registervtkCellValidator(module);
    registervtkCleanPolyData(module);
    registervtkCompositeCutter(module);
    registervtkComputeQuartiles(module);
    registervtkConnectivityFilter(module);
    registervtkContourFilter(module);
    registervtkCountFaces(module);
    registervtkCountVertices(module);
    registervtkCurvatures(module);
    registervtkDataSetRegionSurfaceFilter(module);
    registervtkDataSetSurfaceFilter(module);
    registervtkDataSetTriangleFilter(module);
    registervtkDecimatePolylineFilter(module);
    registervtkDecimatePro(module);
    registervtkDelaunay2D(module);
    registervtkDelaunay3D(module);
    registervtkDistributedDataFilter(module);
    registervtkElevationFilter(module);
    registervtkEvenlySpacedStreamlines2D(module);
    registervtkExtractBlock(module);
    registervtkExtractCTHPart(module);
    registervtkExtractDataSets(module);
    registervtkExtractEdges(module);
    registervtkExtractEnclosedPoints(module);
    registervtkExtractGeometry(module);
    registervtkExtractLevel(module);
    registervtkExtractTimeSteps(module);
    registervtkFeatureEdges(module);
    registervtkForceTime(module);
    registervtkGaussianSplatter(module);
    registervtkGenericClip(module);
    registervtkGenericContourFilter(module);
    registervtkGenericCutter(module);
    registervtkGenericDataSetTessellator(module);
    registervtkGenericGeometryFilter(module);
    registervtkGenericOutlineFilter(module);
    registervtkGenericStreamTracer(module);
    registervtkGradientFilter(module);
    registervtkHyperTreeGridAxisClip(module);
    registervtkHyperTreeGridAxisCut(module);
    registervtkHyperTreeGridAxisReflection(module);
    registervtkHyperTreeGridCellCenters(module);
    registervtkHyperTreeGridContour(module);
    registervtkHyperTreeGridDepthLimiter(module);
    registervtkHyperTreeGridGeometry(module);
    registervtkHyperTreeGridPlaneCutter(module);
    registervtkHyperTreeGridThreshold(module);
    registervtkHyperTreeGridToDualGrid(module);
    registervtkHyperTreeGridToUnstructuredGrid(module);
    registervtkIdFilter(module);
    registervtkImageClip(module);
    registervtkImageDataToPointSet(module);
    registervtkImageDataToUniformGrid(module);
    registervtkImageGradient(module);
    registervtkImageGradientMagnitude(module);
    registervtkImageMapToColors(module);
    registervtkImageMedian3D(module);
    registervtkImageShrink3D(module);
    registervtkImageToAMR(module);
    registervtkIntegrateAttributes(module);
    registervtkLinearSubdivisionFilter(module);
    registervtkLoopSubdivisionFilter(module);
    registervtkMergeArrays(module);
    registervtkMeshQuality(module);
    registervtkMoleculeAppend(module);
    registervtkMoleculeToLinesFilter(module);
    registervtkMultiBlockDataGroupFilter(module);
    registervtkOverlappingAMRLevelIdScalars(module);
    registervtkPCellDataToPointData(module);
    registervtkPExtractDataArraysOverTime(module);
    registervtkPExtractExodusGlobalTemporalVariables(module);
    registervtkPExtractSelectedArraysOverTime(module);
    registervtkPMaskPoints(module);
    registervtkPOutlineCornerFilter(module);
    registervtkPOutlineFilter(module);
    registervtkPPolyDataNormals(module);
    registervtkPProbeFilter(module);
    registervtkPReflectionFilter(module);
    registervtkPResampleFilter(module);
    registervtkParticlePathFilter(module);
    registervtkParticleTracer(module);
    registervtkPassArrays(module);
    registervtkPassThrough(module);
    registervtkPlaneCutter(module);
    registervtkPointDataToCellData(module);
    registervtkPointSetToMoleculeFilter(module);
    registervtkProcessIdScalars(module);
    registervtkQuadraturePointInterpolator(module);
    registervtkQuadraturePointsGenerator(module);
    registervtkQuadratureSchemeDictionaryGenerator(module);
    registervtkQuadricClustering(module);
    registervtkRTXMLPolyDataReader(module);
    registervtkRandomAttributeGenerator(module);
    registervtkRectilinearGridGeometryFilter(module);
    registervtkRectilinearGridToPointSet(module);
    registervtkRemoveGhosts(module);
    registervtkResampleToImage(module);
    registervtkResampleWithDataSet(module);
    registervtkRibbonFilter(module);
    registervtkRotationalExtrusionFilter(module);
    registervtkShrinkFilter(module);
    registervtkSimpleBondPerceiver(module);
    registervtkSmoothPolyDataFilter(module);
    registervtkStreaklineFilter(module);
    registervtkStreamTracer(module);
    registervtkStripper(module);
    registervtkStructuredGridOutlineFilter(module);
    registervtkSynchronizeTimeFilter(module);
    registervtkTableFFT(module);
    registervtkTableToPolyData(module);
    registervtkTableToStructuredGrid(module);
    registervtkTemporalArrayOperatorFilter(module);
    registervtkTemporalDataSetCache(module);
    registervtkTemporalInterpolator(module);
    registervtkTemporalPathLineFilter(module);
    registervtkTemporalShiftScale(module);
    registervtkTemporalSnapToTimeStep(module);
    registervtkTemporalStatistics(module);
    registervtkTensorGlyph(module);
    registervtkTessellatorFilter(module);
    registervtkTextureMapToCylinder(module);
    registervtkTextureMapToPlane(module);
    registervtkTextureMapToSphere(module);
    registervtkThreshold(module);
    registervtkTransformFilter(module);
    registervtkTriangleFilter(module);
    registervtkTubeFilter(module);
    registervtkUnstructuredGridGhostCellsGenerator(module);
    registervtkWarpScalar(module);
    registervtkWarpVector(module);
    registervtkXMLDataObjectWriter(module);
    registervtkXMLHierarchicalBoxDataReader(module);
    registervtkXMLHyperTreeGridReader(module);
    registervtkXMLImageDataReader(module);
    registervtkXMLImageDataWriter(module);
    registervtkXMLMultiBlockDataReader(module);
    registervtkXMLPHyperTreeGridReader(module);
    registervtkXMLPImageDataReader(module);
    registervtkXMLPPolyDataReader(module);
    registervtkXMLPRectilinearGridReader(module);
    registervtkXMLPStructuredGridReader(module);
    registervtkXMLPTableReader(module);
    registervtkXMLPUnstructuredGridReader(module);
    registervtkXMLPartitionedDataSetCollectionReader(module);
    registervtkXMLPartitionedDataSetReader(module);
    registervtkXMLPolyDataReader(module);
    registervtkXMLRectilinearGridReader(module);
    registervtkXMLStructuredGridReader(module);
    registervtkXMLTableReader(module);
    registervtkXMLUniformGridAMRReader(module);
    registervtkXMLUnstructuredGridReader(module);
    registervtkYoungsMaterialInterface(module);
}

}  // namespace ttkwrapper
}  // namespace inviwo
