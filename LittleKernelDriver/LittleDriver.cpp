#include <ntddk.h>
#include <wdm.h>

void WdmDriverUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("Driver unload\n"));
}


extern "C"

NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	KdPrint(("Driver initialized successfully\n"));

	RTL_OSVERSIONINFOW info = { sizeof(info) };
	RtlGetVersion(&info);
	KdPrint(("Windows OS version:%d.%d Build:%d\n", info.dwMajorVersion, info.dwMinorVersion, info.dwBuildNumber));

	DriverObject->DriverUnload = WdmDriverUnload;

	return STATUS_SUCCESS;
}