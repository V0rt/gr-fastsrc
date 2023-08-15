/* -*- c++ -*- */
/*
 * Copyright 2023 V0rt.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_FASTSRC_LFM_CHIRP_IMPL_H
#define INCLUDED_FASTSRC_LFM_CHIRP_IMPL_H

#include <gnuradio/analog/sig_source.h>
#include <gnuradio/fastsrc/lfm_chirp.h>
#include <gnuradio/thread/thread.h>

namespace gr {
namespace fastsrc {
using namespace std;
class lfm_chirp_impl : public lfm_chirp
{
private:
    float samp_rate = 1;
    float freq_deviation = 1;
    float freq_offset = 0;
    float period = 1;
    float phi0 = 0;

    vector<gr_complex> samples;
    size_t num_samples = 0;
    size_t ptr = 0;

    void update_signal();
    

public:
    lfm_chirp_impl(float samp_rate,
                   float freq_deviation,
                   float freq_offset,
                   float period);
    ~lfm_chirp_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);


    void set_samp_rate(float samp_rate);
    void set_period(float period);
    void set_freq_dev(float fd);
    void set_freq_offset(float ofst);
};

} // namespace fastsrc
} // namespace gr

#endif /* INCLUDED_FASTSRC_LFM_CHIRP_IMPL_H */
