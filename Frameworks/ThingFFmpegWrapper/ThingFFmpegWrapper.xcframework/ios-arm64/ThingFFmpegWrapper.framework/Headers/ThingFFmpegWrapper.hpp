/*
 *  ffmpeg.h
 *  This file is part of AVPlayerTouch framework.
 *
 *  Global FFMPEG library header files.
 *
 *  Created by iMoreApps on 3/4/2017.
 *  Copyright (C) 2017 iMoreApps Inc. All rights reserved.
 *  Author: imoreapps <imoreapps@gmail.com>
 */

#ifndef __ThingFFmpegWrapper_H__
#define __ThingFFmpegWrapper_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <libavformat/avio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avassert.h>
#include <libavutil/avutil.h>
#include <libavutil/avstring.h>
#include <libavfilter/avfilter.h>
#include <libavfilter/buffersrc.h>
#include <libavfilter/buffersink.h>
#include <libavutil/dict.h>
#include <libavutil/opt.h>
#include <libavutil/samplefmt.h>
#include <libavutil/frame.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include "libavutil/channel_layout.h"
#include "libavformat/avformat.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/mathematics.h"

/*
 * FFmpeg API bridge
 */

void thing_avcodec_register_all(void);

int thing_av_usleep(unsigned usec);

int64_t thing_av_gettime(void);

void *thing_av_mallocz(size_t size) av_malloc_attrib av_alloc_size(1);

void *thing_av_calloc(size_t nmemb, size_t size) av_malloc_attrib;

void *thing_av_malloc(size_t size) av_malloc_attrib av_alloc_size(1);

AVPacket *thing_av_packet_alloc(void);

void thing_av_packet_free(AVPacket **pkt);

int thing_avcodec_parameters_from_context(AVCodecParameters *par,
                                    const AVCodecContext *codec);

int thing_avio_open(AVIOContext **s, const char *url, int flags);

int thing_avformat_alloc_output_context2(AVFormatContext **ctx, ff_const59 AVOutputFormat *oformat,
                                   const char *format_name, const char *filename);

AVStream *thing_avformat_new_stream(AVFormatContext *s, const AVCodec *c);

int thing_av_write_trailer(AVFormatContext *s);

int thing_avio_closep(AVIOContext **s);

void thing_avformat_free_context(AVFormatContext *s);

int thing_av_interleaved_write_frame(AVFormatContext *s, AVPacket *pkt);

int thing_avformat_write_header(AVFormatContext *s, AVDictionary **options);

ff_const59 AVOutputFormat *thing_av_guess_format(const char *short_name,
                                const char *filename,
                                const char *mime_type);

AVCodec *thing_avcodec_find_encoder(enum AVCodecID id);

int thing_avio_close(AVIOContext *s);

int thing_avcodec_send_frame(AVCodecContext *avctx, const AVFrame *frame);

int thing_avcodec_receive_packet(AVCodecContext *avctx, AVPacket *avpkt);


int thing_av_image_fill_arrays(uint8_t *dst_data[4], int dst_linesize[4],
                         const uint8_t *src,
                         enum AVPixelFormat pix_fmt, int width, int height, int align);

int thing_av_new_packet(AVPacket *pkt, int size);

int thing_av_write_frame(AVFormatContext *s, AVPacket *pkt);

int thing_avio_close(AVIOContext *s);

int thing_av_find_best_stream(AVFormatContext *ic,
                        enum AVMediaType type,
                        int wanted_stream_nb,
                        int related_stream,
                        AVCodec **decoder_ret,
                        int flags);
int thing_av_frame_get_buffer(AVFrame *frame, int align);

void thing_av_free_packet(AVPacket *pkt);

void thing_sws_freeContext(struct SwsContext *swsContext);

int thing_av_get_bytes_per_sample(enum AVSampleFormat sample_fmt);

int thing_sws_scale(struct SwsContext *c, const uint8_t *const srcSlice[],
              const int srcStride[], int srcSliceY, int srcSliceH,
              uint8_t *const dst[], const int dstStride[]);

int thing_avcodec_receive_frame(AVCodecContext *avctx, AVFrame *frame);

int thing_avcodec_send_packet(AVCodecContext *avctx, const AVPacket *avpkt);

void thing_av_free(void *ptr);

void thing_av_freep(void *ptr);

uint32_t thing_av_q2intfloat(AVRational q);

size_t thing_av_strlcat(char *dst, const char *src, size_t size);

void thing_av_log_set_level(int level);

void thing_av_log_set_flags(int arg);

int thing_av_log_get_flags(void);

void thing_av_log(void *avcl, int level, const char *fmt, ...);

void thing_av_register_all(void);

int thing_avformat_network_init(void);

void thing_av_init_packet(AVPacket *pkt);

void thing_av_packet_unref(AVPacket *pkt);

AVFrame *thing_av_frame_alloc(void);

void thing_av_frame_free(AVFrame **frame);

void thing_av_frame_unref(AVFrame *frame);

AVOutputFormat *thing_av_oformat_next(const AVOutputFormat *f);

AVInputFormat *thing_av_iformat_next(const AVInputFormat *f);

AVCodec *thing_av_codec_next(const AVCodec *c);

int thing_av_codec_is_encoder(const AVCodec *codec);

int thing_av_codec_is_decoder(const AVCodec *codec);

void thing_av_codec_set_lowres(AVCodecContext *avctx, int val);

void thing_av_codec_set_pkt_timebase(AVCodecContext *avctx, AVRational val);

int thing_avcodec_open2(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);

void thing_avcodec_free_context(AVCodecContext **avctx);

int thing_avcodec_close(AVCodecContext *avctx);

AVCodecContext *thing_avcodec_alloc_context3(const AVCodec *codec);

int thing_avcodec_parameters_to_context(AVCodecContext *codec, const AVCodecParameters *par);

AVCodec *thing_avcodec_find_decoder(enum AVCodecID id);

const AVCodecDescriptor *thing_avcodec_descriptor_get(enum AVCodecID id);

const AVCodecDescriptor *thing_avcodec_descriptor_next(const AVCodecDescriptor *prev);

int thing_avcodec_fill_audio_frame(AVFrame *frame, int nb_channels,
        enum AVSampleFormat sample_fmt, const uint8_t *buf,
        int buty_size, int align);

void thing_avcodec_flush_buffers(AVCodecContext *avctx);

int thing_avcodec_decode_audio4(AVCodecContext *avctx, AVFrame *frame,
        int *got_frame_ptr, const AVPacket *avpkt);

int thing_avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture,
        int *got_picture_ptr,
        const AVPacket *avpkt);

int thing_avcodec_decode_subtitle2(AVCodecContext *avctx, AVSubtitle *sub,
        int *got_sub_ptr,
        AVPacket *avpkt);

AVDictionaryEntry *thing_av_dict_get(const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags);

int thing_av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);

const AVOption *thing_av_opt_find(void *obj, const char *name, const char *unit, int opt_flags, int search_flags);

void thing_av_dict_free(AVDictionary **m);

int thing_av_samples_get_buffer_size(int *linesize, int nb_channels, int nb_samples, enum AVSampleFormat sample_fmt, int align);

AVRational thing_av_guess_sample_aspect_ratio(AVFormatContext *format, AVStream *stream, AVFrame *frame);

int thing_av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);

int thing_av_frame_get_channels(const AVFrame *frame);

int64_t thing_av_get_default_channel_layout(int nb_channels);

int thing_av_get_channel_layout_nb_channels(uint64_t channel_layout);

int64_t thing_av_frame_get_best_effort_timestamp(const AVFrame *frame);

int thing_swr_init(struct SwrContext *s);

struct SwsContext *thing_sws_getCachedContext(struct SwsContext *context,
                                        int srcW, int srcH, enum AVPixelFormat srcFormat,
                                        int dstW, int dstH, enum AVPixelFormat dstFormat,
                                        int flags, SwsFilter *srcFilter,
                                           SwsFilter *dstFilter, const double *param);

struct SwsContext *thing_sws_getContext(int srcW, int srcH, enum AVPixelFormat srcFormat,
                                  int dstW, int dstH, enum AVPixelFormat dstFormat,
                                  int flags, SwsFilter *srcFilter,
                                     SwsFilter *dstFilter, const double *param);

void thing_swr_free(struct SwrContext **s);

struct SwrContext *thing_swr_alloc(void);

struct SwrContext *thing_swr_alloc_set_opts(struct SwrContext *s,
        int64_t out_ch_layout, enum AVSampleFormat out_sample_fmt, int out_sample_rate,
        int64_t in_ch_layout, enum AVSampleFormat in_sample_fmt, int in_sample_rate,
        int log_offset, void *log_ctx);

int thing_swr_convert(struct SwrContext *s, uint8_t **out, int out_count, const uint8_t **in, int in_count);

int thing_avpicture_alloc(AVPicture *picture, enum AVPixelFormat pix_fmt, int width, int height);

int thing_avpicture_fill(AVPicture *picture, const uint8_t *ptr, enum AVPixelFormat pix_fmt, int width, int height);

AVIOContext *thing_avio_alloc_context(unsigned char *buffer,
        int buffer_size,
        int write_flag,
        void *opaque,
        int (*read_packet)(void *opaque, uint8_t *buf, int buty_size),
        int (*write_packet)(void *opaque, uint8_t *buf, int buty_size),
        int64_t (*seek)(void *opaque, int64_t offset, int whence));

int thing_av_probe_input_buffer(AVIOContext *pb, AVInputFormat **fmt,
        const char *url, void *logctx,
        unsigned int offset, unsigned int max_probe_size);

int thing_avformat_open_input(AVFormatContext **ps, const char *url, AVInputFormat *fmt, AVDictionary **options);

AVInputFormat *thing_av_find_input_format(const char *short_name);

int thing_avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options);

void thing_av_dump_format(AVFormatContext *ic, int index, const char *url, int is_output);

AVFormatContext *thing_avformat_alloc_context(void);

void thing_avformat_close_input(AVFormatContext **s);

const AVClass *thing_avformat_get_class(void);

int thing_avformat_seek_file(AVFormatContext *s, int stream_index, int64_t min_ts, int64_t ts, int64_t max_ts, int flags);

int thing_av_read_frame(AVFormatContext *s, AVPacket *pkt);

int thing_av_read_pause(AVFormatContext *s);

int thing_av_read_play(AVFormatContext *s);

int thing_av_strerror(int errnum, char *errbuf, size_t errbuty_size);

static inline char *thing_av_make_error_string(char *errbuf, size_t errbuty_size, int errnum) {
    thing_av_strerror(errnum, errbuf, errbuty_size);
    return errbuf;
}
int thing_av_image_get_buffer_size(enum AVPixelFormat pix_fmt, int width, int height, int align);

const char *thing_av_get_sample_fmt_name(enum AVSampleFormat sample_fmt);

int thing_av_buffersink_get_frame(AVFilterContext *ctx, AVFrame *frame);

int thing_av_buffersrc_add_frame_flags(AVFilterContext *ctx, AVFrame *frame, int flags);

const AVFilter *thing_avfilter_get_by_name(const char *name);

AVFilterGraph *thing_avfilter_graph_alloc(void);

int thing_avfilter_graph_config(AVFilterGraph *graphctx, void *log_ctx);

int thing_avfilter_graph_create_filter(AVFilterContext **filt_ctx, const AVFilter *filt,
                                  const char *name, const char *args, void *opaque,
                                  AVFilterGraph *graph_ctx);

void thing_avfilter_graph_free(AVFilterGraph **graph);

int thing_avfilter_graph_parse_ptr(AVFilterGraph *graph, const char *filters,
                              AVFilterInOut **inputs, AVFilterInOut **outputs,
                              void *log_ctx);

AVFilterInOut *thing_avfilter_inout_alloc(void);

void thing_avfilter_inout_free(AVFilterInOut **inout);

#define thing_av_err2str(errnum) \
    thing_av_make_error_string((char[AV_ERROR_MAX_STRING_SIZE]){0}, AV_ERROR_MAX_STRING_SIZE, errnum)

#ifdef __cplusplus
}
#endif


#endif // _FFMPEG_H
