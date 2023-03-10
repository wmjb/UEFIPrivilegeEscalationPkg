// based on ipatch_rcm_sample.c provided by ktemkin (https://gist.github.com/ktemkin/825d5f4316f63a7c11ea851a2022415a)
// unmodified copy of original source can also be found at https://github.com/tofurky/tegra30_debrick/payload/ipatch_rcm_sample.c
// ipatch_word(), unipatch_word(), dump_word(), and dump_byte() are more or less unmodified.
// clock/uart initialization and offsets have been consolidated and modified for tegra30

// begin original header
/**
 * Proof of Concept Payload
 * prints out SBK and then enables non-secure RCM 
 *
 * (some code based on coreboot)
 * ~ktemkin
 */
// end original header

#include <stdint.h>
#include "system_regs.h"
#include "tegra30_uart.h"
#include "printf.h"
#include "mmu_dump.h"


void main()
{
	// Check if Security Related Registers can be written

	// CP15SDISABLE & CFGSDISABLE
	*((uint32_t*)0x6000C208) |= (0 << 4) | (0 << 5);


//	MC_SMMU_CONFIG_0 = h10
//	MC 7000:f000
	*((uint32_t*)0x7000f010) = 0;

	clear_ns();

	disable_mmu();

	uint32_t reg = get_mpidr();

	printf("CORE:%d secondary about to loop\r\n",reg & 0x03);

	do{}while(1);
}

