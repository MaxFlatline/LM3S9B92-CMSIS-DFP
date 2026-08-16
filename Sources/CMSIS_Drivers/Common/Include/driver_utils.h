/*
 * Copyright (c) 2026 Max "Flatline" Hodnenko. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CORE_UTILS_H
#define CORE_UTILS_H

/**
  \file     core_utils.h
  \brief    Common bit manipulation macros for hardware drivers
  \version  V1.0.0
  \date     31. July 2026
 */

/* Standard Bit Manipulation Macros */
#define SET_BIT(REG, BIT_NUM)                ((REG) |= (1UL << (BIT_NUM)))
#define CLEAR_BIT(REG, BIT_NUM)              ((REG) &= ~(1UL << (BIT_NUM)))
#define READ_BIT(REG, BIT_NUM)               (((REG) >> (BIT_NUM)) & 1UL)

/* Bit Evaluation Macros */
#define IS_BIT_SET(REG, BIT_NUM)             (((REG) & (1UL << (BIT_NUM))) != 0UL)
#define IS_BIT_CLEAR(REG, BIT_NUM)           (((REG) & (1UL << (BIT_NUM))) == 0UL)

/* Standard Register Manipulation Macros */
#define SET_REG(REG, MASK)                   ((REG) |= (MASK))
#define CLEAR_REG(REG, MASK)                 ((REG) &= ~(MASK))
#define READ_REG(REG, MASK)                  ((REG) & (MASK))

/* Register Evaluation Macros */
#define IS_REG_SET(REG, MASK)                (((REG) & (MASK)) != 0UL)
#define IS_REG_CLEAR(REG, MASK)              (((REG) & (MASK)) == 0UL)

/* Advanced Register Field Modification Macro */
#define WRITE_REG(REG, VAL)                  ((REG) = (VAL))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  ((REG) = (((REG) & (~(CLEARMASK))) | (SETMASK)))

#endif /* CORE_UTILS_H */
