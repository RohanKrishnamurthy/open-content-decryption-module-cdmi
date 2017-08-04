/*
 * Copyright (c) 2017 Fraunhofer FOKUS
 *
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * OpenCDM XDR to be used for RPC communication between DRM and CDM platform counterpart
 * Based on EME methods and naming.
 */

 struct rpc_cb_message {
    uint16_t session_id <>;
    string message <>;
    string destination_url <>;
};


struct rpc_cb_ready {
    uint16_t session_id <>;
};


struct rpc_cb_error {
    uint16_t session_id <>;
    int error;
    string error_message <>;
};

program OPEN_CDM_CALLBACK {
    version OPEN_CDM_EME_5 {
    void ON_MESSAGE(rpc_cb_message) = 1;
    void ON_READY(rpc_cb_ready) = 2;
    void ON_ERROR(rpc_cb_error) = 3;
    } = 1;
} = 0x66666666;
