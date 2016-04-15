#!/bin/sh

FILE=$1

SYMBOLS="
xo_buffer_s
xo_buffer_t
xo_stack_s
xo_stack_t
xo_handle_s
xo_handle_t
xo_default_handle
xo_default_inited
xo_realloc
xo_free
xo_write_to_file
xo_close_file
xo_buf_init
xo_init_handle
xo_default_init
xo_buf_has_room
xo_printf
xo_escape_xml
xo_escape_json
xo_buf_append
xo_buf_escape
xo_data_append
xo_data_escape
xo_default
xo_indent
xo_warn
xo_create
xo_create_to_file
xo_destroy
xo_set_style
xo_set_flags
xo_set_info
xo_set_formatter
xo_clear_flags
xo_buf_indent
xo_line_ensure_open
xo_line_close
xo_info_compare
xo_info_find
xo_format_data
xo_buf_append_div
xo_format_text
xo_format_label
xo_format_title
xo_format_prep
xo_format_value
xo_format_decoration
xo_format_padding
xo_do_emit
xo_emit_hv
xo_emit_h
xo_emit
xo_attr_hv
xo_attr_h
xo_attr
xo_depth_change
xo_open_container_h
xo_open_container
xo_close_container_h
xo_close_container
xo_open_list_h
xo_open_list
xo_close_list_h
xo_close_list
xo_open_instance_h
xo_open_instance
xo_close_instance_h
xo_close_instance
xo_set_writer
xo_set_allocator
"
