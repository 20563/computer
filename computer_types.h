#ifndef _COMPUTER_TYPES_H_
#define _COMPUTER_TYPES_H_

#if defined(CONFIG_USE_STDINT)
typedef	__INT8_TYPE__		s8;
typedef	__UINT8_TYPE__		u8;
typedef	__INT16_TYPE__		s16;
typedef	__UINT16_TYPE__		u16;
typedef	__INT32_TYPE__		s32;
typedef	__UINT32_TYPE__		u32;
typedef	__INT64_TYPE__		s64;
typedef	__UINT64_TYPE__		u64;
#else
typedef signed char			s8;
typedef unsigned char		u8;
typedef signed short		s16;
typedef unsigned short		u16;
typedef signed int			s32;
typedef unsigned int		u32;
typedef signed long long	s64;
typedef unsigned long long	u64;
#endif

#endif /* _COMPUTER_TYPES_H_ */
