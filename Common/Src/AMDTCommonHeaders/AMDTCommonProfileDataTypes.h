//=============================================================
// (c) 2016 Advanced Micro Devices, Inc.
//
/// \author CodeXL Developer Tools
/// \version $Revision: $
/// \brief Common Data Types used by DB Adapter and Profiler Report layers
//
//=============================================================

#ifndef _AMDTCOMMONPROFILEDATATYPES_H_
#define _AMDTCOMMONPROFILEDATATYPES_H_

// Base headers
#include <AMDTCommonHeaders/AMDTDefinitions.h>
#include <AMDTCommonHeaders/AMDTCommonDataTypes.h>
#include <AMDTBaseTools/Include/gtString.h>
#include <AMDTBaseTools/Include/gtVector.h>

// Temporary macro to enable/disable intermediate DB changes
//#define AMDT_ENABLE_CPUPROF_DB 1

//
//      Macros
//

#define AMDT_PROFILE_MAX_VALUE              0xFFFFFFFFUL
#define AMDT_PROFILE_HW_EVENT_ID_MAX        AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_ALL_PROCESSES          AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_ALL_MODULES            AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_ALL_THREADS            AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_ALL_COUNTERS           AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_ALL_CORES              AMDT_PROFILE_MAX_VALUE
#define AMDT_PROFILE_MAX_COUNT              AMDT_PROFILE_MAX_VALUE

#define AMDT_PROFILE_INVALID_ADDR           ULLONG_MAX

#define UNKNOWN_FUNCTION_ID                 0
#define UNKNOWN_MODULE_ID                   0

typedef AMDTUInt32       AMDTModuleId;
typedef AMDTUInt32       AMDTProcessId;
typedef AMDTUInt32       AMDTThreadId;
typedef AMDTUInt32       AMDTCounterId;
typedef AMDTUInt32       AMDTFunctionId;

struct AMDTProfileSourceLineData;
struct AMDTProfileSourceLineTable;
struct AMDTProfileInstructionData;

//
//  Enums
//

enum AMDTProfileMode
{
    AMDT_PROFILE_MODE_NONE = 0,
    AMDT_PROFILE_MODE_TIMELINE = 1,
    AMDT_PROFILE_MODE_AGGREGATION = 2
};

enum AMDTProfileDataType
{
    AMDT_PROFILE_DATA_PROCESS = 1,
    AMDT_PROFILE_DATA_THREAD,
    AMDT_PROFILE_DATA_MODULE,
    AMDT_PROFILE_DATA_FUNCTION,
};

enum AMDTModuleType
{
    AMDT_MODULE_TYPE_NONE = 0,
    AMDT_MODULE_TYPE_NATIVE = 1,
    AMDT_MODULE_TYPE_JAVA = 2,
    AMDT_MODULE_TYPE_MANAGEDDPE = 3,
    AMDT_MODULE_TYPE_OCL = 4,
    AMDT_MODULE_TYPE_UNKNOWN = 5,
    AMDT_MODULE_TYPE_UNKNOWN_KERNEL = 6,
};

enum AMDTReportOptionType
{
    AMDT_REPORT_OPTION_COREMASK = 1,
    AMDT_REPORT_OPTION_SEP_BY_CORE,
    AMDT_REPORT_OPTION_IGNORE_SYSTEM_MODULE,
    AMDT_REPORT_OPTION_SORT_PROFILE_DATA,
    AMDT_REPORT_OPTION_SUMMARY_COUNT,
};

//
//  Structs
//

struct AMDTProfileDevice
{
    AMDTUInt32              m_deviceId;
    AMDTUInt32              m_deviceType;

    gtString                m_deviceTypeStr;    // The original PP tables/dal/adapter are convoluted @#$%^&
    gtString                m_name;
    gtString                m_description;

    gtVector<AMDTUInt32>    m_subDeviceIds;
};

struct AMDTCpuTopology
{
    AMDTUInt32  m_coreId = AMDT_PROFILE_ALL_CORES;
    AMDTUInt16  m_processorId = 0;
    AMDTUInt16  m_numaNodeId = 0;

    AMDTCpuTopology(AMDTUInt32 coreId, AMDTUInt16 processorId, AMDTUInt16 numaNodeId) :
        m_coreId(coreId), m_processorId(processorId), m_numaNodeId(numaNodeId) {}
};

struct AMDTProfileSystemTime
{
    AMDTUInt64   m_second = 0;
    AMDTUInt64   m_microSecond = 0;
};

struct AMDTProfileSamplingConfig
{
    AMDTUInt32      m_id;                   // samplingConfigurationId
    AMDTUInt32      m_hwEventId;            // actual HW PMC event id
    AMDTUInt64      m_samplingInterval;
    AMDTInt8        m_unitMask;
    bool            m_userMode;
    bool            m_osMode;
};

struct AMDTProfileCounterDesc
{
    AMDTUInt32              m_id;   // samplingConfigurationId
    AMDTUInt32              m_type; // AMDTProfileCounterType.. named as counterAggregation.. actually it is better to have "BASIC" or "CALCULATED"

    // This field will contain:
    //      actual HW PMC event id for AMDT_CPUPROF_COUNTER_TYPE_BASIC type counters
    //      AMDT_CPUPROF_PMC_EVENT_ID_MAX for AMDT_CPUPROF_COUNTER_TYPE_CALCULATED type counters
    AMDTUInt32              m_hwEventId;    // HW PMC event id
    AMDTUInt32              m_deviceId;
    AMDTUInt32              m_category;     // for power it its temp,pwr,freq
    AMDTUInt32              m_unit;         // AMDTProfileCounterUnit count, percent

    gtString                m_name;
    gtString                m_description;

    // these are required due to old pp table design
    gtString                m_typeStr;
    gtString                m_categoryStr;
    gtString                m_unitStr;

    // Sampling Configuration:
    // Valid only for AMDT_CPUPROF_COUNTER_TYPE_BASIC type counters
    AMDTProfileSamplingConfig   m_samplingConfig;

#if 0
    // default ctor
    AMDTProfileCounterDesc() = default;
    // delete default copy ctor
    AMDTProfileCounterDesc(const AMDTProfileCounterDesc& other) = delete;
#endif //0
};

struct AMDTProfileDataOptions
{
    gtVector<AMDTUInt32>    m_counters;     // counters on which the queries will be selected
    gtUInt64                m_coreMask = 0;
    bool                    m_isSeperateByCore = false;
    bool                    m_doSort = true;
    bool                    m_ignoreSystemModules = true;
    size_t                  m_summaryCount = 5;

    void Clear(void)
    {
        m_counters.clear();
        m_coreMask = 0;
        m_isSeperateByCore = false;
        m_doSort = false;
        m_ignoreSystemModules = false;
        m_summaryCount = 0;
    };
};


// From a session profile data various reports can be generated using the sampled counters and the calculated counter like
//      - all data (raw counters)
//      - ipc assessment (cpu-ccyles, retured-microops, cpi, ipc)
struct AMDTProfileReportConfig
{
    AMDTUInt32                          m_id;
    gtString                            m_name;

    // Counters that are supported for this CPU Profile Data View Configuration
    gtVector<AMDTProfileCounterDesc>    m_counterDescs;
};

struct AMDTProfileModuleInfo
{
    AMDTModuleId        m_moduleId = 0;
    AMDTModuleType      m_type = AMDT_MODULE_TYPE_NONE;
    gtString            m_name;
    gtString            m_path;
    AMDTUInt64          m_loadAddress = 0;
    AMDTUInt32          m_size = 0;
    AMDTUInt64          m_checksum = 0;
    bool                m_is64Bit = false;
    bool                m_isSystemModule = false;
    bool                m_isMainModule = false;
    bool                m_foundDebugInfo = false;   // during translation
};

struct AMDTProfileThreadInfo
{
    AMDTThreadId        m_threadId;
    AMDTProcessId       m_pid;
    gtString            m_name;
    AMDTUInt64          m_startTime;
    AMDTUInt64          m_endTime;
};

struct AMDTProfileProcessInfo
{
    AMDTProcessId               m_pid;
    gtString                    m_name;
    gtString                    m_path;
    bool                        m_is64Bit;
    AMDTUInt64                  m_startTime;
    AMDTUInt64                  m_endTime;

    gtVector<AMDTProfileModuleInfo>    m_modulesList;
    gtVector<AMDTProfileThreadInfo>    m_threadsList;
};

struct AMDTProfileFunctionInfo
{
    AMDTFunctionId                          m_functionId;
    gtString                                m_name;

    AMDTModuleId                            m_moduleId;
    gtString                                m_modulePath;   // redundant

    gtUInt64                                m_startOffset;  // w.r.t module base address
    gtUInt32                                m_size;

    bool                                    m_isSrcInfoAvailable = false;
    gtString                                m_sourceFile;
};

struct AMDTSampleValue
{
    AMDTCounterId           m_counterId = AMDT_PROFILE_ALL_COUNTERS;
    AMDTUInt32              m_coreId = AMDT_PROFILE_ALL_CORES; // valid only when seperate-by-core is enabled. should this be deviceId?

    AMDTProfileSystemTime   m_sampleTime;
    AMDTUInt64              m_timeSinceProfileStart = 0; // in milli seconds

    double                  m_sampleCount = 0.0;
    double                  m_sampleCountPercentage = 0.0;
};

struct AMDTProfileData
{
    AMDTProfileDataType         m_type;         // process, module, function, thread?

    AMDTProcessId               m_processId;
    AMDTModuleId                m_moduleId;
    AMDTThreadId                m_threadId;
    AMDTFunctionId              m_functionId;

    gtString                    m_name;         // name of the process/module/function/thread
    gtString                    m_path;         // path of module.. valid for process, module, function(module path)

    gtVector<AMDTSampleValue>   m_sampleValue;

    // TODO:
    // Add ctor add copy ctor
};

struct AMDTProfileInstructionData
{
    AMDTUInt32                      m_offset;           // offset from the beginning of the module. should this be from beginning of the function
    gtVector<AMDTSampleValue>       m_sampleValues;
};

struct AMDTProfileFunctionData
{
    AMDTProfileFunctionInfo                 m_functionInfo;

    AMDTProcessId                           m_pid;              // If AMDT_CP_ALL_PROCESSES, aggregated across all processes
    AMDTThreadId                            m_threadId;

    gtUInt64                                m_modBaseAddress;  // not reqd

    gtVector<AMDTProfileInstructionData>    m_instDataList;
    // TODO: should i add source-line level profile data, srcline table & disassembly for the entire function

    ~AMDTProfileFunctionData()
    {
        clear();
    }

    void clear(void)
    {
        m_instDataList.clear();
    }
};

struct AMDTProfileSourceLineData
{
    AMDTUInt32                      m_sourceLineNumber; // Line number in the source

    AMDTUInt32                      m_offset;           // offset from the beginning of the function - NOT REQUIRED ?
    AMDTUInt32                      m_size;

    gtVector<AMDTSampleValue>       m_sampleValues;

    ~AMDTProfileSourceLineData()
    {
        clear();
    }

    void clear(void)
    {
        m_sampleValues.clear();
    }
};

// Offset range - Source Line Table
struct AMDTProfileSourceLineTable
{
    AMDTUInt32          m_offset;
    AMDTUInt32          m_size;
    AMDTUInt32          m_sourceLineNumber;
};

using AMDTProfileCounterDescVec = gtVector<AMDTProfileCounterDesc>;
using AMDTProfileSamplingConfigVec = gtVector<AMDTProfileSamplingConfig>;

//
//  Temporary structs
//

// This struct is used for sample info insertion into DB
// TODO: this will removed once we optimize translation for DB
struct CPSampleData
{
    // Module Info
    gtUInt32    m_moduleInstanceId = 0;
    gtUInt64    m_pid = 0;
    gtUInt32    m_coreId = 0;

    // Event Info
    gtUInt16    m_event = 0;
    gtUByte     m_unitMask = 0;
    bool        m_bitOs = false;
    bool        m_bitUsr = false;

    // Thread Info
    gtUInt32    m_threadId = 0;

    // Function Info
    gtUInt32    m_functionId = 0;

    // Sample Info
    gtUInt64    m_offset = 0;
    gtUInt64    m_count = 0;
};

struct SampledValue
{
    SampledValue() : m_sampleValue(0.0), m_sampleTime(0) {}
    SampledValue(int sampleTime, double sampleValue) :
        m_sampleValue(sampleValue), m_sampleTime(sampleTime) {}

    // The sample value.
    double  m_sampleValue;

    // The time when the samples was taken.
    int  m_sampleTime;
};

struct SamplingTimeRange
{
    SamplingTimeRange(int fromQuantizedTime, int toQuantizedTime) :
        m_fromTime(fromQuantizedTime), m_toTime(toQuantizedTime) {}

    int  m_fromTime;
    int  m_toTime;
};

//
//  AMDTProfileTimelineSample & AMDTProfileCounterValue are used to instert/query timeline samples
//

struct AMDTProfileCounterValue
{
    AMDTUInt32      m_counterId;
    AMDTFloat32     m_counterValue;
};

// Used by DbAdapter/MidTier
struct AMDTProfileTimelineSample
{
    AMDTProfileSystemTime               m_sampleSystemTime;
    AMDTUInt64                          m_sampleElapsedTimeMs;
    gtVector<AMDTProfileCounterValue>   m_sampleValues;
};

#endif // _AMDTCOMMONPROFILEDATATYPES_H_