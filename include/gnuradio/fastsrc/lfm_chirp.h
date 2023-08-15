/* -*- c++ -*- */
/*
 * Copyright 2023 V0rt.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_FASTSRC_LFM_CHIRP_H
#define INCLUDED_FASTSRC_LFM_CHIRP_H

#include <gnuradio/fastsrc/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace fastsrc {

/*!
 * \brief <+description of block+>
 * \ingroup fastsrc
 *
 */
class FASTSRC_API lfm_chirp : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<lfm_chirp> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of fastsrc::lfm_chirp.
     *
     * To avoid accidental use of raw pointers, fastsrc::lfm_chirp's
     * constructor is in a private implementation
     * class. fastsrc::lfm_chirp::make is the public interface for
     * creating new instances.
     */
    static sptr make(float samp_rate = 1,
                     float freq_deviation = 1,
                     float freq_offset = 0,
                     float period = 1);

    virtual void set_samp_rate(float samp_rate) = 0;
    virtual void set_period(float period) = 0;
    virtual void set_freq_dev(float fd) = 0;
    virtual void set_freq_offset(float ofst) = 0;

};

} // namespace fastsrc
} // namespace gr

#endif /* INCLUDED_FASTSRC_LFM_CHIRP_H */
