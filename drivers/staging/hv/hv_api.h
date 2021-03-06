/*
 *
 * Copyright (c) 2009, Microsoft Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * Authors:
 *   Haiyang Zhang <haiyangz@microsoft.com>
 *   Hank Janssen  <hjanssen@microsoft.com>
 *
 */
#ifndef __HV_API_H
#define __HV_API_H


/* Status codes for hypervisor operations. */

/*
 * HV_STATUS_SUCCESS
 * The specified hypercall succeeded
 */
#define HV_STATUS_SUCCESS				((u16)0x0000)

/*
 * HV_STATUS_INVALID_HYPERCALL_CODE
 * The hypervisor does not support the operation because the specified
 * hypercall code is not supported.
 */
#define HV_STATUS_INVALID_HYPERCALL_CODE		((u16)0x0002)

/*
 * HV_STATUS_INVALID_HYPERCALL_INPUT
 * The hypervisor does not support the operation because the encoding for the
 * hypercall input register is not supported.
 */
#define HV_STATUS_INVALID_HYPERCALL_INPUT		((u16)0x0003)

/*
 * HV_STATUS_INVALID_ALIGNMENT
 * The hypervisor could not perform the operation beacuse a parameter has an
 * invalid alignment.
 */
#define HV_STATUS_INVALID_ALIGNMENT			((u16)0x0004)

/*
 * HV_STATUS_INVALID_PARAMETER
 * The hypervisor could not perform the operation beacuse an invalid parameter
 * was specified.
 */
#define HV_STATUS_INVALID_PARAMETER			((u16)0x0005)

/*
 * HV_STATUS_ACCESS_DENIED
 * Access to the specified object was denied.
 */
#define HV_STATUS_ACCESS_DENIED				((u16)0x0006)

/*
 * HV_STATUS_INVALID_PARTITION_STATE
 * The hypervisor could not perform the operation because the partition is
 * entering or in an invalid state.
 */
#define HV_STATUS_INVALID_PARTITION_STATE		((u16)0x0007)

/*
 * HV_STATUS_OPERATION_DENIED
 * The operation is not allowed in the current state.
 */
#define HV_STATUS_OPERATION_DENIED			((u16)0x0008)

/*
 * HV_STATUS_UNKNOWN_PROPERTY
 * The hypervisor does not recognize the specified partition property.
 */
#define HV_STATUS_UNKNOWN_PROPERTY			((u16)0x0009)

/*
 * HV_STATUS_PROPERTY_VALUE_OUT_OF_RANGE
 * The specified value of a partition property is out of range or violates an
 * invariant.
 */
#define HV_STATUS_PROPERTY_VALUE_OUT_OF_RANGE		((u16)0x000A)

/*
 * HV_STATUS_INSUFFICIENT_MEMORY
 * There is not enough memory in the hypervisor pool to complete the operation.
 */
#define HV_STATUS_INSUFFICIENT_MEMORY			((u16)0x000B)

/*
 * HV_STATUS_PARTITION_TOO_DEEP
 * The maximum partition depth has been exceeded for the partition hierarchy.
 */
#define HV_STATUS_PARTITION_TOO_DEEP			((u16)0x000C)

/*
 * HV_STATUS_INVALID_PARTITION_ID
 * A partition with the specified partition Id does not exist.
 */
#define HV_STATUS_INVALID_PARTITION_ID			((u16)0x000D)

/*
 * HV_STATUS_INVALID_VP_INDEX
 * The hypervisor could not perform the operation because the specified VP
 * index is invalid.
 */
#define HV_STATUS_INVALID_VP_INDEX			((u16)0x000E)

/*
 * HV_STATUS_NOT_FOUND
 * The iteration is complete; no addition items in the iteration could be
 * found.
 */
#define HV_STATUS_NOT_FOUND				((u16)0x0010)

/*
 * HV_STATUS_INVALID_PORT_ID
 * The hypervisor could not perform the operation because the specified port
 * identifier is invalid.
 */
#define HV_STATUS_INVALID_PORT_ID			((u16)0x0011)

/*
 * HV_STATUS_INVALID_CONNECTION_ID
 * The hypervisor could not perform the operation because the specified
 * connection identifier is invalid.
 */
#define HV_STATUS_INVALID_CONNECTION_ID			((u16)0x0012)

/*
 * HV_STATUS_INSUFFICIENT_BUFFERS
 * You did not supply enough message buffers to send a message.
 */
#define HV_STATUS_INSUFFICIENT_BUFFERS			((u16)0x0013)

/*
 * HV_STATUS_NOT_ACKNOWLEDGED
 * The previous virtual interrupt has not been acknowledged.
 */
#define HV_STATUS_NOT_ACKNOWLEDGED			((u16)0x0014)

/*
 * HV_STATUS_INVALID_VP_STATE
 * A virtual processor is not in the correct state for the performance of the
 * indicated operation.
 */
#define HV_STATUS_INVALID_VP_STATE			((u16)0x0015)

/*
 * HV_STATUS_ACKNOWLEDGED
 * The previous virtual interrupt has already been acknowledged.
 */
#define HV_STATUS_ACKNOWLEDGED				((u16)0x0016)

/*
 * HV_STATUS_INVALID_SAVE_RESTORE_STATE
 * The indicated partition is not in a valid state for saving or restoring.
 */
#define HV_STATUS_INVALID_SAVE_RESTORE_STATE		((u16)0x0017)

/*
 * HV_STATUS_INVALID_SYNIC_STATE
 * The hypervisor could not complete the operation because a required feature
 * of the synthetic interrupt controller (SynIC) was disabled.
 */
#define HV_STATUS_INVALID_SYNIC_STATE			((u16)0x0018)

/*
 * HV_STATUS_OBJECT_IN_USE
 * The hypervisor could not perform the operation because the object or value
 * was either already in use or being used for a purpose that would not permit
 * completing the operation.
 */
#define HV_STATUS_OBJECT_IN_USE				((u16)0x0019)

/*
 * HV_STATUS_INVALID_PROXIMITY_DOMAIN_INFO
 * The proximity domain information is invalid.
 */
#define HV_STATUS_INVALID_PROXIMITY_DOMAIN_INFO		((u16)0x001A)

/*
 * HV_STATUS_NO_DATA
 * An attempt to retrieve debugging data failed because none was available.
 */
#define HV_STATUS_NO_DATA				((u16)0x001B)

/*
 * HV_STATUS_INACTIVE
 * The physical connection being used for debuggging has not recorded any
 * receive activity since the last operation.
 */
#define HV_STATUS_INACTIVE				((u16)0x001C)

/*
 * HV_STATUS_NO_RESOURCES
 * There are not enough resources to complete the operation.
 */
#define HV_STATUS_NO_RESOURCES				((u16)0x001D)

/*
 * HV_STATUS_FEATURE_UNAVAILABLE
 * A hypervisor feature is not available to the user.
 */
#define HV_STATUS_FEATURE_UNAVAILABLE			((u16)0x001E)

/*
 * HV_STATUS_UNSUCCESSFUL
 * {Operation Failed} The requested operation was unsuccessful.
 */
#define HV_STATUS_UNSUCCESSFUL				((u16)0x1001)

/*
 * HV_STATUS_INSUFFICIENT_BUFFER
 * The specified buffer was too small to contain all of the requested data.
 */
#define HV_STATUS_INSUFFICIENT_BUFFER			((u16)0x1002)

/*
 * HV_STATUS_GPA_NOT_PRESENT
 * The guest physical address is not currently associated with a system
 * physical address.
 */
#define HV_STATUS_GPA_NOT_PRESENT			((u16)0x1003)

/*
 * HV_STATUS_GUEST_PAGE_FAULT
 * The operation would have resulted in a page fault in the guest.
 */
#define HV_STATUS_GUEST_PAGE_FAULT			((u16)0x1004)

/*
 * HV_STATUS_RUNDOWN_DISABLED
 * The operation cannot proceed as the rundown object was marked disabled.
 */
#define HV_STATUS_RUNDOWN_DISABLED			((u16)0x1005)

/*
 * HV_STATUS_KEY_ALREADY_EXISTS
 * The entry cannot be added as another entry with the same key already exists.
 */
#define HV_STATUS_KEY_ALREADY_EXISTS			((u16)0x1006)

/*
 * HV_STATUS_GPA_INTERCEPT
 * The operation resulted an intercept on a region of guest physical memory.
 */
#define HV_STATUS_GPA_INTERCEPT				((u16)0x1007)

/*
 * HV_STATUS_GUEST_GENERAL_PROTECTION_FAULT
 * The operation would have resulted in a general protection fault in the
 * guest.
 */
#define HV_STATUS_GUEST_GENERAL_PROTECTION_FAULT	((u16)0x1008)

/*
 * HV_STATUS_GUEST_STACK_FAULT
 * The operation would have resulted in a stack fault in the guest.
 */
#define HV_STATUS_GUEST_STACK_FAULT			((u16)0x1009)

/*
 * HV_STATUS_GUEST_INVALID_OPCODE_FAULT
 * The operation would have resulted in an invalid opcode fault in the guest.
 */
#define HV_STATUS_GUEST_INVALID_OPCODE_FAULT		((u16)0x100A)

/*
 * HV_STATUS_FINALIZE_INCOMPLETE
 * The partition is not completely finalized.
 */
#define HV_STATUS_FINALIZE_INCOMPLETE			((u16)0x100B)

/*
 * HV_STATUS_GUEST_MACHINE_CHECK_ABORT
 * The operation would have resulted in an machine check abort in the guest.
 */
#define HV_STATUS_GUEST_MACHINE_CHECK_ABORT		((u16)0x100C)

/*
 * HV_STATUS_ILLEGAL_OVERLAY_ACCESS
 * An illegal access was attempted to an overlay page.
 */
#define HV_STATUS_ILLEGAL_OVERLAY_ACCESS		((u16)0x100D)

/*
 * HV_STATUS_INSUFFICIENT_SYSTEM_VA
 * There is not enough system VA space available to satisfy the request,
 */
#define HV_STATUS_INSUFFICIENT_SYSTEM_VA		((u16)0x100E)

/*
 * HV_STATUS_VIRTUAL_ADDRESS_NOT_MAPPED
 * The passed virtual address was not mapped in the hypervisor address space.
 */
#define HV_STATUS_VIRTUAL_ADDRESS_NOT_MAPPED		((u16)0x100F)

/*
 * HV_STATUS_NOT_IMPLEMENTED
 * The requested operation is not implemented in this version of the
 * hypervisor.
 */
#define HV_STATUS_NOT_IMPLEMENTED			((u16)0x1010)

/*
 * HV_STATUS_VMX_INSTRUCTION_FAILED
 * The requested VMX instruction failed to complete successfully.
 */
#define HV_STATUS_VMX_INSTRUCTION_FAILED		((u16)0x1011)

/*
 * HV_STATUS_VMX_INSTRUCTION_FAILED_WITH_STATUS
 * The requested VMX instruction failed to complete successfully indicating
 * status.
 */
#define HV_STATUS_VMX_INSTRUCTION_FAILED_WITH_STATUS	((u16)0x1012)

/*
 * HV_STATUS_MSR_ACCESS_FAILED
 * The requested access to the model specific register failed.
 */
#define HV_STATUS_MSR_ACCESS_FAILED		((u16)0x1013)

/*
 * HV_STATUS_CR_ACCESS_FAILED
 * The requested access to the control register failed.
 */
#define HV_STATUS_CR_ACCESS_FAILED		((u16)0x1014)

/*
 * HV_STATUS_TIMEOUT
 * The specified timeout expired before the operation completed.
 */
#define HV_STATUS_TIMEOUT			((u16)0x1016)

/*
 * HV_STATUS_MSR_INTERCEPT
 * The requested access to the model specific register generated an intercept.
 */
#define HV_STATUS_MSR_INTERCEPT			((u16)0x1017)

/*
 * HV_STATUS_CPUID_INTERCEPT
 * The CPUID instruction generated an intercept.
 */
#define HV_STATUS_CPUID_INTERCEPT		((u16)0x1018)

/*
 * HV_STATUS_REPEAT_INSTRUCTION
 * The current instruction should be repeated and the instruction pointer not
 * advanced.
 */
#define HV_STATUS_REPEAT_INSTRUCTION		((u16)0x1019)

/*
 * HV_STATUS_PAGE_PROTECTION_VIOLATION
 * The current instruction should be repeated and the instruction pointer not
 * advanced.
 */
#define HV_STATUS_PAGE_PROTECTION_VIOLATION	((u16)0x101A)

/*
 * HV_STATUS_PAGE_TABLE_INVALID
 * The current instruction should be repeated and the instruction pointer not
 * advanced.
 */
#define HV_STATUS_PAGE_TABLE_INVALID		((u16)0x101B)

/*
 * HV_STATUS_PAGE_NOT_PRESENT
 * The current instruction should be repeated and the instruction pointer not
 * advanced.
 */
#define HV_STATUS_PAGE_NOT_PRESENT		((u16)0x101C)

/*
 * HV_STATUS_IO_INTERCEPT
 * The requested access to the I/O port generated an intercept.
 */
#define HV_STATUS_IO_INTERCEPT				((u16)0x101D)

/*
 * HV_STATUS_NOTHING_TO_DO
 * There is nothing to do.
 */
#define HV_STATUS_NOTHING_TO_DO				((u16)0x101E)

/*
 * HV_STATUS_THREAD_TERMINATING
 * The requested thread is terminating.
 */
#define HV_STATUS_THREAD_TERMINATING			((u16)0x101F)

/*
 * HV_STATUS_SECTION_ALREADY_CONSTRUCTED
 * The specified section was already constructed.
 */
#define HV_STATUS_SECTION_ALREADY_CONSTRUCTED		((u16)0x1020)

/* HV_STATUS_SECTION_NOT_ALREADY_CONSTRUCTED
 * The specified section was not already constructed.
 */
#define HV_STATUS_SECTION_NOT_ALREADY_CONSTRUCTED	((u16)0x1021)

/*
 * HV_STATUS_PAGE_ALREADY_COMMITTED
 * The specified virtual address was already backed by physical memory.
 */
#define HV_STATUS_PAGE_ALREADY_COMMITTED		((u16)0x1022)

/*
 * HV_STATUS_PAGE_NOT_ALREADY_COMMITTED
 * The specified virtual address was not already backed by physical memory.
 */
#define HV_STATUS_PAGE_NOT_ALREADY_COMMITTED		((u16)0x1023)

/*
 * HV_STATUS_COMMITTED_PAGES_REMAIN
 * Committed pages remain in the section.
 */
#define HV_STATUS_COMMITTED_PAGES_REMAIN		((u16)0x1024)

/*
 * HV_STATUS_NO_REMAINING_COMMITTED_PAGES
 * No additional committed pages beyond the specified page exist in the
 * section.
 */
#define HV_STATUS_NO_REMAINING_COMMITTED_PAGES		((u16)0x1025)

/*
 * HV_STATUS_INSUFFICIENT_COMPARTMENT_VA
 * The VA space of the compartment is exhausted.
 */
#define HV_STATUS_INSUFFICIENT_COMPARTMENT_VA		((u16)0x1026)

/*
 * HV_STATUS_DEREF_SPA_LIST_FULL
 * The SPA dereference list is full, and there are additional entries to be
 * added to it.
 */
#define HV_STATUS_DEREF_SPA_LIST_FULL			((u16)0x1027)

/*
 * HV_STATUS_GPA_OUT_OF_RANGE
 * The supplied GPA is out of range.
 */
#define HV_STATUS_GPA_OUT_OF_RANGE			((u16)0x1027)

/*
 * HV_STATUS_NONVOLATILE_XMM_STALE
 * The XMM register that was being accessed is stale.
 */
#define HV_STATUS_NONVOLATILE_XMM_STALE			((u16)0x1028)

/* HV_STATUS_UNSUPPORTED_PROCESSOR
 * The hypervisor does not support the processors in this system.
 */
#define HV_STATUS_UNSUPPORTED_PROCESSOR			((u16)0x1029)

/*
 * HV_STATUS_INSUFFICIENT_CROM_SPACE
 * Insufficient space existed for copying over the CROM contents.
 */
#define HV_STATUS_INSUFFICIENT_CROM_SPACE		((u16)0x2000)

/*
 * HV_STATUS_BAD_CROM_FORMAT
 * The contents of the CROM failed validation attempts.
 */
#define HV_STATUS_BAD_CROM_FORMAT			((u16)0x2001)

/*
 * HV_STATUS_UNSUPPORTED_CROM_FORMAT
 * The contents of the CROM contain contents the parser doesn't support.
 */
#define HV_STATUS_UNSUPPORTED_CROM_FORMAT		((u16)0x2002)

/*
 * HV_STATUS_UNSUPPORTED_CONTROLLER
 * The register format of the OHCI controller specified for debugging is not
 * supported.
 */
#define HV_STATUS_UNSUPPORTED_CONTROLLER		((u16)0x2003)

/*
 * HV_STATUS_CROM_TOO_LARGE
 * The CROM contents were to large to copy over.
 */
#define HV_STATUS_CROM_TOO_LARGE			((u16)0x2004)

/*
 * HV_STATUS_CONTROLLER_IN_USE
 * The OHCI controller specified for debugging cannot be used as it is already
 * in use.
 */
#define HV_STATUS_CONTROLLER_IN_USE			((u16)0x2005)


/*
 * The below CPUID leaves are present if VersionAndFeatures.HypervisorPresent
 * is set by CPUID(HVCPUID_VERSION_FEATURES).
 */
enum hv_cpuid_function {
	HVCPUID_VERSION_FEATURES		= 0x00000001,
	HVCPUID_VENDOR_MAXFUNCTION		= 0x40000000,
	HVCPUID_INTERFACE			= 0x40000001,

	/*
	 * The remaining functions depend on the value of
	 * HVCPUID_INTERFACE
	 */
	HVCPUID_VERSION			= 0x40000002,
	HVCPUID_FEATURES			= 0x40000003,
	HVCPUID_ENLIGHTENMENT_INFO	= 0x40000004,
	HVCPUID_IMPLEMENTATION_LIMITS		= 0x40000005,
};

/* Define the virtual APIC registers */
#define HV_X64_MSR_EOI			(0x40000070)
#define HV_X64_MSR_ICR			(0x40000071)
#define HV_X64_MSR_TPR			(0x40000072)
#define HV_X64_MSR_APIC_ASSIST_PAGE	(0x40000073)

/* Define version of the synthetic interrupt controller. */
#define HV_SYNIC_VERSION		(1)

/* Define synthetic interrupt controller model specific registers. */
#define HV_X64_MSR_SCONTROL		(0x40000080)
#define HV_X64_MSR_SVERSION		(0x40000081)
#define HV_X64_MSR_SIEFP		(0x40000082)
#define HV_X64_MSR_SIMP			(0x40000083)
#define HV_X64_MSR_EOM			(0x40000084)
#define HV_X64_MSR_SINT0		(0x40000090)
#define HV_X64_MSR_SINT1		(0x40000091)
#define HV_X64_MSR_SINT2		(0x40000092)
#define HV_X64_MSR_SINT3		(0x40000093)
#define HV_X64_MSR_SINT4		(0x40000094)
#define HV_X64_MSR_SINT5		(0x40000095)
#define HV_X64_MSR_SINT6		(0x40000096)
#define HV_X64_MSR_SINT7		(0x40000097)
#define HV_X64_MSR_SINT8		(0x40000098)
#define HV_X64_MSR_SINT9		(0x40000099)
#define HV_X64_MSR_SINT10		(0x4000009A)
#define HV_X64_MSR_SINT11		(0x4000009B)
#define HV_X64_MSR_SINT12		(0x4000009C)
#define HV_X64_MSR_SINT13		(0x4000009D)
#define HV_X64_MSR_SINT14		(0x4000009E)
#define HV_X64_MSR_SINT15		(0x4000009F)

/* Define the expected SynIC version. */
#define HV_SYNIC_VERSION_1		(0x1)

/* Define synthetic interrupt controller message constants. */
#define HV_MESSAGE_SIZE			(256)
#define HV_MESSAGE_PAYLOAD_BYTE_COUNT	(240)
#define HV_MESSAGE_PAYLOAD_QWORD_COUNT	(30)
#define HV_ANY_VP			(0xFFFFFFFF)

/* Define synthetic interrupt controller flag constants. */
#define HV_EVENT_FLAGS_COUNT		(256 * 8)
#define HV_EVENT_FLAGS_BYTE_COUNT	(256)
#define HV_EVENT_FLAGS_DWORD_COUNT	(256 / sizeof(u32))

/* Define hypervisor message types. */
enum hv_message_type {
	HVMSG_NONE			= 0x00000000,

	/* Memory access messages. */
	HVMSG_UNMAPPED_GPA		= 0x80000000,
	HVMSG_GPA_INTERCEPT		= 0x80000001,

	/* Timer notification messages. */
	HVMSG_TIMER_EXPIRED			= 0x80000010,

	/* Error messages. */
	HVMSG_INVALID_VP_REGISTER_VALUE	= 0x80000020,
	HVMSG_UNRECOVERABLE_EXCEPTION	= 0x80000021,
	HVMSG_UNSUPPORTED_FEATURE		= 0x80000022,

	/* Trace buffer complete messages. */
	HVMSG_EVENTLOG_BUFFERCOMPLETE	= 0x80000040,

	/* Platform-specific processor intercept messages. */
	HVMSG_X64_IOPORT_INTERCEPT		= 0x80010000,
	HVMSG_X64_MSR_INTERCEPT		= 0x80010001,
	HVMSG_X64_CPUID_INTERCEPT		= 0x80010002,
	HVMSG_X64_EXCEPTION_INTERCEPT	= 0x80010003,
	HVMSG_X64_APIC_EOI			= 0x80010004,
	HVMSG_X64_LEGACY_FP_ERROR		= 0x80010005
};

/* Define the number of synthetic interrupt sources. */
#define HV_SYNIC_SINT_COUNT		(16)
#define HV_SYNIC_STIMER_COUNT		(4)

/* Define invalid partition identifier. */
#define HV_PARTITION_ID_INVALID		((u64)0x0)

/* Define connection identifier type. */
union hv_connection_id {
	u32 asu32;
	struct {
		u32 id:24;
		u32 reserved:8;
	} u;
};

/* Define port identifier type. */
union hv_port_id {
	u32 asu32;
	struct {
		u32 id:24;
		u32 reserved:8;
	} u ;
};

/* Define port type. */
enum hv_port_type {
	HVPORT_MSG	= 1,
	HVPORT_EVENT		= 2,
	HVPORT_MONITOR	= 3
};

/* Define port information structure. */
struct hv_port_info {
	enum hv_port_type port_type;
	u32 padding;
	union {
		struct {
			u32 target_sint;
			u32 target_vp;
			u64 rsvdz;
		} message_port_info;
		struct {
			u32 target_sint;
			u32 target_vp;
			u16 base_flag_bumber;
			u16 flag_count;
			u32 rsvdz;
		} event_port_info;
		struct {
			u64 monitor_address;
			u64 rsvdz;
		} monitor_port_info;
	};
};

struct hv_connection_info {
	enum hv_port_type port_type;
	u32 padding;
	union {
		struct {
			u64 rsvdz;
		} message_connection_info;
		struct {
			u64 rsvdz;
		} event_connection_info;
		struct {
			u64 monitor_address;
		} monitor_connection_info;
	};
};

/* Define synthetic interrupt controller message flags. */
union hv_message_flags {
	u8 asu8;
	struct {
		u8 msg_pending:1;
		u8 reserved:7;
	};
};

/* Define synthetic interrupt controller message header. */
struct hv_message_header {
	enum hv_message_type message_type;
	u8 payload_size;
	union hv_message_flags message_flags;
	u8 reserved[2];
	union {
		u64 sender;
		union hv_port_id port;
	};
};

/* Define timer message payload structure. */
struct hv_timer_message_payload {
	u32 timer_index;
	u32 reserved;
	u64 expiration_time;	/* When the timer expired */
	u64 delivery_time;	/* When the message was delivered */
};

/* Define synthetic interrupt controller message format. */
struct hv_message {
	struct hv_message_header header;
	union {
		u64 payload[HV_MESSAGE_PAYLOAD_QWORD_COUNT];
	} u ;
};

/* Define the number of message buffers associated with each port. */
#define HV_PORT_MESSAGE_BUFFER_COUNT	(16)

/* Define the synthetic interrupt message page layout. */
struct hv_message_page {
	struct hv_message sint_message[HV_SYNIC_SINT_COUNT];
};

/* Define the synthetic interrupt controller event flags format. */
union hv_synic_event_flags {
	u8 flags8[HV_EVENT_FLAGS_BYTE_COUNT];
	u32 flags32[HV_EVENT_FLAGS_DWORD_COUNT];
};

/* Define the synthetic interrupt flags page layout. */
struct hv_synic_event_flags_page {
	union hv_synic_event_flags sintevent_flags[HV_SYNIC_SINT_COUNT];
};

/* Define SynIC control register. */
union hv_synic_scontrol {
	u64 as_uint64;
	struct {
		u64 enable:1;
		u64 reserved:63;
	};
};

/* Define synthetic interrupt source. */
union hv_synic_sint {
	u64 as_uint64;
	struct {
		u64 vector:8;
		u64 reserved1:8;
		u64 masked:1;
		u64 auto_eoi:1;
		u64 reserved2:46;
	};
};

/* Define the format of the SIMP register */
union hv_synic_simp {
	u64 as_uint64;
	struct {
		u64 simp_enabled:1;
		u64 preserved:11;
		u64 base_simp_gpa:52;
	};
};

/* Define the format of the SIEFP register */
union hv_synic_siefp {
	u64 as_uint64;
	struct {
		u64 siefp_enabled:1;
		u64 preserved:11;
		u64 base_siefp_gpa:52;
	};
};

/* Definitions for the monitored notification facility */
union hv_monitor_trigger_group {
	u64 as_uint64;
	struct {
		u32 pending;
		u32 armed;
	};
};

struct hv_monitor_parameter {
	union hv_connection_id connectionid;
	u16 flagnumber;
	u16 rsvdz;
};

union hv_monitor_trigger_state {
	u32 asu32;

	struct {
		u32 group_enable:4;
		u32 rsvdz:28;
	};
};

/* struct hv_monitor_page Layout */
/* ------------------------------------------------------ */
/* | 0   | TriggerState (4 bytes) | Rsvd1 (4 bytes)     | */
/* | 8   | TriggerGroup[0]                              | */
/* | 10  | TriggerGroup[1]                              | */
/* | 18  | TriggerGroup[2]                              | */
/* | 20  | TriggerGroup[3]                              | */
/* | 28  | Rsvd2[0]                                     | */
/* | 30  | Rsvd2[1]                                     | */
/* | 38  | Rsvd2[2]                                     | */
/* | 40  | NextCheckTime[0][0]    | NextCheckTime[0][1] | */
/* | ...                                                | */
/* | 240 | Latency[0][0..3]                             | */
/* | 340 | Rsvz3[0]                                     | */
/* | 440 | Parameter[0][0]                              | */
/* | 448 | Parameter[0][1]                              | */
/* | ...                                                | */
/* | 840 | Rsvd4[0]                                     | */
/* ------------------------------------------------------ */
struct hv_monitor_page {
	union hv_monitor_trigger_state trigger_state;
	u32 rsvdz1;

	union hv_monitor_trigger_group trigger_group[4];
	u64 rsvdz2[3];

	s32 next_checktime[4][32];

	u16 latency[4][32];
	u64 rsvdz3[32];

	struct hv_monitor_parameter parameter[4][32];

	u8 rsvdz4[1984];
};

/* Declare the various hypercall operations. */
enum hv_call_code {
	HVCALL_POST_MESSAGE	= 0x005c,
	HVCALL_SIGNAL_EVENT	= 0x005d,
};

/* Definition of the hv_post_message hypercall input structure. */
struct hv_input_post_message {
	union hv_connection_id connectionid;
	u32 reserved;
	enum hv_message_type message_type;
	u32 payload_size;
	u64 payload[HV_MESSAGE_PAYLOAD_QWORD_COUNT];
};

/* Definition of the hv_signal_event hypercall input structure. */
struct hv_input_signal_event {
	union hv_connection_id connectionid;
	u16 flag_number;
	u16 rsvdz;
};

/*
 * Versioning definitions used for guests reporting themselves to the
 * hypervisor, and visa versa.
 */

/* Version info reported by guest OS's */
enum hv_guest_os_vendor {
	HVGUESTOS_VENDOR_MICROSOFT	= 0x0001
};

enum hv_guest_os_microsoft_ids {
	HVGUESTOS_MICROSOFT_UNDEFINED	= 0x00,
	HVGUESTOS_MICROSOFT_MSDOS		= 0x01,
	HVGUESTOS_MICROSOFT_WINDOWS3X	= 0x02,
	HVGUESTOS_MICROSOFT_WINDOWS9X	= 0x03,
	HVGUESTOS_MICROSOFT_WINDOWSNT	= 0x04,
	HVGUESTOS_MICROSOFT_WINDOWSCE	= 0x05
};

/*
 * Declare the MSR used to identify the guest OS.
 */
#define HV_X64_MSR_GUEST_OS_ID	0x40000000

union hv_x64_msr_guest_os_id_contents {
	u64 as_uint64;
	struct {
		u64 build_number:16;
		u64 service_version:8; /* Service Pack, etc. */
		u64 minor_version:8;
		u64 major_version:8;
		u64 os_id:8; /* enum hv_guest_os_microsoft_ids (if Vendor=MS) */
		u64 vendor_id:16; /* enum hv_guest_os_vendor */
	};
};

/*
 * Declare the MSR used to setup pages used to communicate with the hypervisor.
 */
#define HV_X64_MSR_HYPERCALL	0x40000001

union hv_x64_msr_hypercall_contents {
	u64 as_uint64;
	struct {
		u64 enable:1;
		u64 reserved:11;
		u64 guest_physical_address:52;
	};
};

#endif
