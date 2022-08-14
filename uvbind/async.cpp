/*******************************************************************************
 * Copyright © 2016 Hudyaev Alexy <hudyaev.alexy@gmail.com>
 *
 * This file is part of cpphttpx
 *
 * CPPHTTPX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CPPHTTPX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with cpphttpx (copying file in the root of this repository). If not,
 * see <http://www.gnu.org/licenses/>
 * *****************************************************************************/

#include "async.h"
#include "errors.h"

uvbind::async::async(uvbind::loop_ptr l, const callback_type& cb)
    : callbackable_handle(l)
{
	int r=uv_async_init(bound_loop(),holder_.get(),[](uv_async_t* h){
	      auto& dt=uv_callback(h);
	      dt.cb(dt.self); });
	prepare_holder(r,cb);
}

uvbind::async::~async() noexcept
{
}

void uvbind::async::send()
{
	int r=uv_async_send(holder_.get());
	if(r) throw error(r);
}