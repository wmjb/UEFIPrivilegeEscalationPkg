# UEFI Privilege Escalation Exploit: Trustzone Exploit that allows running code in secure mode on Surface RT (Tegra 3) with the help of Yahallo (by imbushuo)

This tool allows you to run any given code in the Secure PL1 state of the Cortex-A9 CPU cores. This is based of off [Yahallo by imbushuo](https://github.com/NekomimiRouter/yahallo).

More information will follow.


payload - core0 payload. output as payload.bin to be copied to root of usb drive
          
          payload is loaded by efi app into 0x80112174 core 0 smc handler via mmu disable.
          
payload2 - core1> payload. output as payload2.bin to be copied to root of usb drive
          
          payload2 is loaded by efi app into 0x83100000 and called by writing the address to 0x82002880 core 1 smc handler.
          
sec_payload - core 1 smc call payload, output as payload_secondary.bin to be copied to root of usb drive
          
          payload_secondary.bin is loaded by efi app into 0x83800000 and called by mailbox entry point of parked secondary core.  

# License

This code is released under GPLv2.


