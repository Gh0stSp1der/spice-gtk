/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2010 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __SPICE_CLIENT_SESSION_H__
#define __SPICE_CLIENT_SESSION_H__

#include <glib-object.h>
#include "spice-types.h"
#include "spice-glib-enums.h"
#include "spice-util.h"

G_BEGIN_DECLS

#define SPICE_TYPE_SESSION            (spice_session_get_type ())
#define SPICE_SESSION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), SPICE_TYPE_SESSION, SpiceSession))
#define SPICE_SESSION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), SPICE_TYPE_SESSION, SpiceSessionClass))
#define SPICE_IS_SESSION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SPICE_TYPE_SESSION))
#define SPICE_IS_SESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SPICE_TYPE_SESSION))
#define SPICE_SESSION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), SPICE_TYPE_SESSION, SpiceSessionClass))

struct _SpiceSession
{
    GObject parent;
    spice_session *priv;
    /* Do not add fields to this struct */
};

struct _SpiceSessionClass
{
    GObjectClass parent_class;

    /* signals */
    void (*channel_new)(SpiceSession *session, SpiceChannel *channel);
    void (*channel_destroy)(SpiceSession *session, SpiceChannel *channel);

    /*< private >*/
    /*
     * If adding fields to this struct, remove corresponding
     * amount of padding to avoid changing overall struct size
     */
    gchar _spice_reserved[SPICE_RESERVED_PADDING];
};

GType spice_session_get_type(void) G_GNUC_CONST;

SpiceSession *spice_session_new(void);
gboolean spice_session_connect(SpiceSession *session);
gboolean spice_session_open_fd(SpiceSession *session, int fd);
void spice_session_disconnect(SpiceSession *session);
GList *spice_session_get_channels(SpiceSession *session);

G_END_DECLS

#endif /* __SPICE_CLIENT_SESSION_H__ */
