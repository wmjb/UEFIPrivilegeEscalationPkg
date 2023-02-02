# UEFI Privilege Escalation Exploit: Trustzone Exploit that allows running code in secure mode on Surface RT (Tegra 3) with the help of Yahallo (by imbushuo)

This tool allows you to run any given code in the Secure PL1 state of the Cortex-A9 CPU cores. This is based of off [Yahallo by imbushuo](https://github.com/NekomimiRouter/yahallo).


what we have here is the efi app loading the exploit payload into core 0 smc handler, also loading an exploit payload2 into memory for core 1. the efi app sets the smc call address of core 1 to it's exploit payload in memory. the secondary core is launched with an entry point pointing to a "payload_ secondary" payload loaded by the efi app, which is just asm of an smc call. then the efi app waits for clearing of mailbox of core 1.
once the mailbox is cleared the core 0 payload launches u-boot put in memory by the efi app.

More information will follow.




payload - core0 payload. output as payload.bin to be copied to root of usb drive
          
          payload is loaded by efi app into 0x80112174 core 0 smc handler via mmu disable.
          
payload2 - core1> payload. output as payload2.bin to be copied to root of usb drive
          
          payload2 is loaded by efi app into 0x83100000 and called by writing the address to 0x82002880 core 1 smc handler.
          
sec_payload - core 1 smc call payload, output as payload_secondary.bin to be copied to root of usb drive
          
          payload_secondary.bin is loaded by efi app into 0x83800000 and called by mailbox entry point of parked secondary core.  

# License

This code is released under GPLv2.


