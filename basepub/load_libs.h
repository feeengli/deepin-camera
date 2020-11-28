/*
* Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
* Maintainer: shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LOAD_LIBS_H
#define LOAD_LIBS_H
#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <pthread.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
//#include <libavutil/dict.h>
#include <libffmpegthumbnailer/videothumbnailerc.h>
//AVCodec *avcodec_find_encoder(enum AVCodecID id);
typedef AVCodec *(*uos_avcodec_find_encoder)(enum AVCodecID id);
//AVCodec *avcodec_find_decoder(enum AVCodecID id);
typedef AVCodec *(*uos_avcodec_find_decoder)(enum AVCodecID id);
typedef AVCodec *(*uos_avcodec_find_encoder_by_name)(const char *name);
typedef AVCodecContext *(*uos_avcodec_alloc_context)(const AVCodec *codec);
typedef AVCodecContext *(*uos_avcodec_alloc_context3)(const AVCodec *codec);
//int avcodec_get_context_defaults3(AVCodecContext *s, const AVCodec *codec);
typedef int (*uos_avcodec_get_context_defaults3)(AVCodecContext *s, const AVCodec *codec);
//int avcodec_open2(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);
typedef int (*uos_avcodec_open2)(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);
//void avcodec_flush_buffers(AVCodecContext *avctx);
typedef void (*uos_avcodec_flush_buffers)(AVCodecContext *avctx);
//int avcodec_close(AVCodecContext *avctx);
typedef int (*uos_avcodec_close)(AVCodecContext *avctx);
//int avcodec_parameters_from_context(AVCodecParameters *par,const AVCodecContext *codec);
typedef int (*uos_avcodec_parameters_from_context)(AVCodecParameters *par,const AVCodecContext *codec);
//int avcodec_send_packet(AVCodecContext *avctx, const AVPacket *avpkt);
typedef int (*uos_avcodec_send_packet)(AVCodecContext *avctx, const AVPacket *avpkt);
//int avcodec_receive_frame(AVCodecContext *avctx, AVFrame *frame);
typedef int (*uos_avcodec_receive_frame)(AVCodecContext *avctx, AVFrame *frame);
//int avcodec_receive_packet(AVCodecContext *avctx, AVPacket *avpkt);
typedef int (*uos_avcodec_receive_packet)(AVCodecContext *avctx, AVPacket *avpkt);
//void av_packet_free(AVPacket **pkt);
typedef void (*uos_av_packet_free)(AVPacket **pkt);
//int avcodec_fill_audio_frame(AVFrame *frame, int nb_channels,enum AVSampleFormat sample_fmt, const uint8_t *buf,int buf_size, int align);
typedef int (*uos_avcodec_fill_audio_frame)(AVFrame *frame, int nb_channels, enum AVSampleFormat sample_fmt, const uint8_t *buf, int buf_size, int align);
//void av_packet_unref(AVPacket *pkt);
typedef void (*uos_av_packet_unref)(AVPacket *pkt);
//int avcodec_send_frame(AVCodecContext *avctx, const AVFrame *frame);
typedef int (*uos_avcodec_send_frame)(AVCodecContext *avctx, const AVFrame *frame);
//void av_packet_rescale_ts(AVPacket *pkt, AVRational tb_src, AVRational tb_dst);
typedef void (*uos_av_packet_rescale_ts)(AVPacket *pkt, AVRational tb_src, AVRational tb_dst);
//void av_init_packet(AVPacket *pkt);
typedef void (*uos_av_init_packet)(AVPacket *pkt);
//AVPacket *av_packet_alloc(void);
typedef AVPacket *(*uos_av_packet_alloc)(void);

typedef int (*uos_avformat_open_input)(AVFormatContext **ps, const char *url, AVInputFormat *fmt, AVDictionary **options);
typedef int (*uos_avformat_find_stream_info)(AVFormatContext *ic, AVDictionary **options);
typedef int (*uos_av_find_best_stream)(AVFormatContext *ic, enum AVMediaType type, int wanted_stream_nb, int related_stream, AVCodec **decoder_ret, int flags);
typedef void (*uos_av_dump_format)(AVFormatContext *ic, int index, const char *url, int is_output);
typedef void (*uos_avformat_close_input)(AVFormatContext **s);
//int avformat_alloc_output_context2(AVFormatContext **ctx, AVOutputFormat *oformat,const char *format_name, const char *filename);
typedef int (*uos_avformat_alloc_output_context2)(AVFormatContext **ctx, AVOutputFormat *oformat,const char *format_name, const char *filename);
//AVStream *avformat_new_stream(AVFormatContext *s, const AVCodec *c);
typedef AVStream *(*uos_avformat_new_stream)(AVFormatContext *s, const AVCodec *c);
//void avformat_free_context(AVFormatContext *s);
typedef void (*uos_avformat_free_context)(AVFormatContext *s);
//int avformat_write_header(AVFormatContext *s, AVDictionary **options);
typedef int (*uos_avformat_write_header)(AVFormatContext *s, AVDictionary **options);
//int avio_open(AVIOContext **s, const char *url, int flags);
typedef int (*uos_avio_open)(AVIOContext **s, const char *url, int flags);
//int av_write_frame(AVFormatContext *s, AVPacket *pkt);
typedef int (*uos_av_write_frame)(AVFormatContext *s, AVPacket *pkt);
//int av_write_trailer(AVFormatContext *s);
typedef int (*uos_av_write_trailer)(AVFormatContext *s);
//int avio_closep(AVIOContext **s);
typedef int (*uos_avio_closep)(AVIOContext **s);


typedef video_thumbnailer *(*uos_video_thumbnailer)();
typedef void (*uos_video_thumbnailer_destroy)(video_thumbnailer *thumbnailer);
/* create image_data structure */
typedef image_data *(*uos_video_thumbnailer_create_image_data)(void);
/* destroy image_data structure */
typedef void (*uos_video_thumbnailer_destroy_image_data)(image_data *data);
typedef int (*uos_video_thumbnailer_generate_thumbnail_to_buffer)(video_thumbnailer *thumbnailer, const char *movie_filename, image_data *generated_image_data);

//lswresample
//void swr_free(struct SwrContext **s);
typedef void (*uos_swr_free)(struct SwrContext **s);

//lswscale
//void sws_freeContext(struct SwsContext *swsContext);
typedef void (*uos_sws_freeContext)(struct SwsContext *swsContext);

//libavutil不到1M
typedef AVDictionaryEntry *(*uos_av_dict_get)(const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags);
//int av_strerror(int errnum, char *errbuf, size_t errbuf_size);
typedef int (*uos_av_strerror)(int errnum, char *errbuf, size_t errbuf_size);
//int av_dict_copy(AVDictionary **dst, const AVDictionary *src, int flags);
typedef int (*uos_av_dict_copy)(AVDictionary **dst, const AVDictionary *src, int flags);
//void av_dict_free(AVDictionary **m);
typedef void (*uos_av_dict_free)(AVDictionary **m);
//int av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);
typedef int (*uos_av_dict_set)(AVDictionary **pm, const char *key, const char *value, int flags);
//int av_dict_set_int(AVDictionary **pm, const char *key, int64_t value, int flags);
typedef int (*uos_av_dict_set_int)(AVDictionary **pm, const char *key, int64_t value, int flags);
//void av_log_set_level(int level);
typedef void (*uos_av_log_set_level)(int level);
/*int av_image_copy_to_buffer(uint8_t *dst, int dst_size,
const uint8_t * const src_data[4], const int src_linesize[4],
enum AVPixelFormat pix_fmt, int width, int height, int align);*/
typedef int (*uos_av_image_copy_to_buffer)(uint8_t *dst, int dst_size,
const uint8_t * const src_data[4], const int src_linesize[4],
enum AVPixelFormat pix_fmt, int width, int height, int align);
//void av_frame_free(AVFrame **frame);
typedef void (*uos_av_frame_free)(AVFrame **frame);
//AVFrame *av_frame_alloc(void);
typedef AVFrame *(*uos_av_frame_alloc)(void);
//void av_freep(void *ptr);
typedef void (*uos_av_freep)(void *ptr);
//void av_frame_unref(AVFrame *frame);
typedef void (*uos_av_frame_unref)(AVFrame *frame);
//void av_free(void *ptr);
typedef void (*uos_av_free)(void *ptr);
/*int av_samples_get_buffer_size(int *linesize, int nb_channels, int nb_samples,
                               enum AVSampleFormat sample_fmt, int align);*/
typedef int (*uos_av_samples_get_buffer_size)(int *linesize, int nb_channels, int nb_samples,
                               enum AVSampleFormat sample_fmt, int align);
//const char *av_get_media_type_string(enum AVMediaType media_type);
typedef const char *(*uos_av_get_media_type_string)(enum AVMediaType media_type);
//int av_image_get_buffer_size(enum AVPixelFormat pix_fmt, int width, int height, int align);
typedef int (*uos_av_image_get_buffer_size)(enum AVPixelFormat pix_fmt, int width, int height, int align);
typedef struct _LoadLibs
{
    uos_avcodec_find_encoder m_avcodec_find_encoder;
    uos_avcodec_find_decoder m_avcodec_find_decoder;
    uos_avcodec_find_encoder_by_name m_avcodec_find_encoder_by_name;
    uos_avcodec_alloc_context m_avcodec_alloc_context;
    uos_avcodec_alloc_context3 m_avcodec_alloc_context3;
    uos_avcodec_get_context_defaults3 m_avcodec_get_context_defaults3;
    uos_avcodec_open2 m_avcodec_open2;
    uos_avcodec_flush_buffers m_avcodec_flush_buffers;
    uos_avcodec_close m_avcodec_close;
    uos_avcodec_parameters_from_context m_avcodec_parameters_from_context;
    uos_avcodec_send_packet m_avcodec_send_packet;
    uos_avcodec_receive_frame m_avcodec_receive_frame;
    uos_avcodec_receive_packet m_avcodec_receive_packet;
    uos_av_packet_free m_av_packet_free;
    uos_avcodec_fill_audio_frame m_avcodec_fill_audio_frame;
    uos_av_packet_unref m_av_packet_unref;
    uos_avcodec_send_frame m_avcodec_send_frame;
    uos_av_packet_rescale_ts m_av_packet_rescale_ts;
    uos_av_init_packet m_av_init_packet;
    uos_av_packet_alloc m_av_packet_alloc;

    uos_avformat_open_input m_avformat_open_input;
    uos_avformat_find_stream_info m_avformat_find_stream_info;
    uos_av_find_best_stream m_av_find_best_stream;
    uos_av_dump_format m_av_dump_format;
    uos_avformat_close_input m_avformat_close_input;
    uos_avformat_alloc_output_context2 m_avformat_alloc_output_context2;
    uos_avformat_new_stream m_avformat_new_stream;
    uos_avformat_free_context m_avformat_free_context;
    uos_avformat_write_header m_avformat_write_header;
    uos_avio_open m_avio_open;
    uos_av_write_frame m_av_write_frame;
    uos_av_write_trailer m_av_write_trailer;
    uos_avio_closep m_avio_closep;


    uos_video_thumbnailer m_video_thumbnailer;
    uos_video_thumbnailer_destroy m_video_thumbnailer_destroy;
    uos_video_thumbnailer_create_image_data m_video_thumbnailer_create_image_data;
    uos_video_thumbnailer_destroy_image_data m_video_thumbnailer_destroy_image_data;
    uos_video_thumbnailer_generate_thumbnail_to_buffer m_video_thumbnailer_generate_thumbnail_to_buffer;


    uos_swr_free m_swr_free;

    uos_sws_freeContext m_sws_freeContext;


    uos_av_dict_get m_av_dict_get;
    uos_av_strerror m_av_strerror;
    uos_av_dict_copy m_av_dict_copy;
    uos_av_dict_free m_av_dict_free;
    uos_av_dict_set m_av_dict_set;
    uos_av_dict_set_int m_av_dict_set_int;
    uos_av_log_set_level m_av_log_set_level;
    uos_av_image_copy_to_buffer m_av_image_copy_to_buffer;
    uos_av_frame_free m_av_frame_free;
    uos_av_frame_alloc m_av_frame_alloc;
    uos_av_freep m_av_freep;
    uos_av_frame_unref m_av_frame_unref;
    uos_av_free m_av_free;
    uos_av_samples_get_buffer_size m_av_samples_get_buffer_size;
    uos_av_get_media_type_string m_av_get_media_type_string;//
    uos_av_image_get_buffer_size m_av_image_get_buffer_size;
} LoadLibs;

LoadLibs *getLoadLibsInstance();//饿汉式不支持延迟加载

#endif//LOAD_LIBS_H
