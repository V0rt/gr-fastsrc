/* -*- c++ -*- */
/*
 * Copyright 2023 V0rt.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "lfm_chirp_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace fastsrc {

#pragma message("set the following appropriately and remove this warning")
using output_type = gr_complex;
lfm_chirp::sptr
lfm_chirp::make(float samp_rate, float freq_deviation, float freq_offset, float period)
{
    return gnuradio::make_block_sptr<lfm_chirp_impl>(
        samp_rate, freq_deviation, freq_offset, period);
}


/*
 * The private constructor
 */
lfm_chirp_impl::lfm_chirp_impl(float d_samp_rate,
                               float d_freq_deviation,
                               float d_freq_offset,
                               float d_period)
    : gr::sync_block("lfm_chirp",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
      samp_rate(d_samp_rate),
      freq_deviation(d_freq_deviation),
      freq_offset(d_freq_offset),
      period(d_period)
{
    num_samples = period * samp_rate;
    freq_deviation = freq_deviation / samp_rate;
    freq_offset = freq_offset / samp_rate;

    cout << "samp_rate " << samp_rate << endl;
    cout << "freq_dev " << freq_deviation << endl;
    cout << "freq_ofst " << freq_offset << endl;
    cout << "period " << period << endl;

    vector<gr_complex> temp(num_samples);

    for (int i = 0; i < num_samples; i++) {
        temp[i] = exp(gr_complex(0,
                                 2 * M_PI *
                                     ((freq_offset - freq_deviation / 2) * i +
                                      freq_deviation * i * i / 2 / (float)num_samples)));
    }

    while (samples.size() < num_samples + 4096) {
        samples.insert(samples.end(), temp.begin(), temp.end());
    }
}

/*
 * Our virtual destructor.
 */
lfm_chirp_impl::~lfm_chirp_impl() {}

int lfm_chirp_impl::work(int noutput_items,
                         gr_vector_const_void_star& input_items,
                         gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

    if (noutput_items + ptr > samples.size())
        cout << "noutput_items " << noutput_items << "+ptr " << ptr << " samples.size() "
             << samples.size() << endl;

    copy(samples.begin() + ptr, samples.begin() + ptr + noutput_items, out);
    ptr = (ptr + noutput_items) % num_samples;

    return noutput_items;
}


void lfm_chirp_impl::set_samp_rate(float sr)
{
    cout << __PRETTY_FUNCTION__ << "__NOT_IMPLEMENTED__" << endl;
}

void lfm_chirp_impl::set_period(float p)
{
    cout << __PRETTY_FUNCTION__ << endl;
    num_samples = period * samp_rate;
    update_signal();
}

void lfm_chirp_impl::set_freq_dev(float fd)
{
    cout << __PRETTY_FUNCTION__ << endl;
    freq_deviation = fd / samp_rate;
    update_signal();
}

void lfm_chirp_impl::set_freq_offset(float ofst)
{
    cout << __PRETTY_FUNCTION__ << endl;
    freq_offset = ofst / samp_rate;
    update_signal();
}

void lfm_chirp_impl::update_signal()
{
    cout << __PRETTY_FUNCTION__ << endl;
    samples.clear();
    vector<gr_complex> temp(num_samples);

    for (int i = 0; i < num_samples; i++) {
        temp[i] = exp(gr_complex(0,
                                 2 * M_PI *
                                     ((freq_offset - freq_deviation / 2) * i +
                                      freq_deviation * i * i / 2 / (float)num_samples)));
    }
    while (samples.size() < period + 4096) {
        samples.insert(samples.end(), temp.begin(), temp.end());
    }
    ptr = 0;
}

} /* namespace fastsrc */
} /* namespace gr */
