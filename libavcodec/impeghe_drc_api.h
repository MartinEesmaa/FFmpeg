/* 	Copyright (c) [2022] Ittiam Systems Pvt. Ltd.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted (subject to the limitations in the
   disclaimer below) provided that the following conditions are met:
   •	Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   •	Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   •	Neither the names of Dolby Laboratories, Inc. (or its affiliates),
   Ittiam Systems Pvt. Ltd. nor the names of its contributors may be used
   to endorse or promote products derived from this software without
   specific prior written permission.

   NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED
   BY THIS LICENSE. YOUR USE OF THE SOFTWARE MAY REQUIRE ADDITIONAL PATENT
   LICENSE(S) BY THIRD PARTIES, INCLUDING, WITHOUT LIMITATION, DOLBY
   LABORATORIES, INC. OR ANY OF ITS AFFILIATES. THIS SOFTWARE IS PROVIDED
   BY ITTIAM SYSTEMS LTD. AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
   OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
   IN NO EVENT SHALL ITTIAM SYSTEMS LTD OR ITS CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------
*/

#ifndef IMPEGHE_DRC_API_H
#define IMPEGHE_DRC_API_H
typedef struct
{
  WORD32 frame_size;
  WORD32 sample_rate;
  WORD32 delay_mode;
  WORD32 domain;
  WORD32 parametric_drc_only;
  WORD32 frame_count;
  WORD32 gain_sequence_present;
} ia_drc_enc_params_struct;

typedef struct
{
  ia_drc_enc_params_struct str_enc_params;
  ia_drc_uni_drc_config_struct str_uni_drc_config;
  ia_drc_loudness_info_set_struct str_enc_loudness_info_set;
  ia_drc_uni_drc_gain_ext_struct str_enc_gain_extension;
} ia_drc_input_config;

IA_ERRORCODE impeghe_drc_enc_init(VOID *pstr_drc_state, VOID *ptr_drc_scratch,
                                  ia_drc_input_config *pstr_inp_config);

VOID impeghe_drc_enc(VOID *pstr_drc_state, FLOAT32 **pptr_input, UWORD32 inp_offset,
                     WORD32 *ptr_bits_written, VOID *pstr_scratch);

#endif /*IMPEGHE_DRC_API_H*/
