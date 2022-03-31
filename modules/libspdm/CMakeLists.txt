if(CONFIG_LIBSPDM)
    set(LIBSPDM_DIR ${ZEPHYR_CURRENT_MODULE_DIR})
    set(LIBSPDM_ZEPHYR_DIR ${CMAKE_CURRENT_LIST_DIR})
    set(ARCH "arm")

    zephyr_library()
    zephyr_include_directories(
        include
        "${LIBSPDM_DIR}"
        "${LIBSPDM_DIR}/include"
        "${LIBSPDM_DIR}/include/hal"
        "${LIBSPDM_DIR}/include/hal/${ARCH}"
    )

    zephyr_library_sources(
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_context_data.c
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_context_data_session.c
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_crypto_service.c
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_crypto_service_session.c
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_opaque_data.c
        ${LIBSPDM_DIR}/library/spdm_common_lib/libspdm_com_support.c
    )

    zephyr_library_sources(
        ${LIBSPDM_DIR}/library/spdm_crypt_lib/libspdm_crypt_crypt.c
    )

    zephyr_library_sources_ifdef(
        LIBSPDM_REQUESTER
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_challenge.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_communication.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_certificate.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_challenge_auth.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_digests.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_error.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_key_update.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_encap_request.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_end_session.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_finish.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_get_capabilities.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_get_certificate.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_get_digests.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_get_measurements.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_get_version.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_handle_error_response.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_heartbeat.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_key_exchange.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_key_update.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_negotiate_algorithms.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_psk_exchange.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_psk_finish.c
        ${LIBSPDM_DIR}/library/spdm_requester_lib/libspdm_req_send_receive.c
    )

    zephyr_library_sources_ifdef(
        LIBSPDM_RESPONDER
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_algorithms.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_capabilities.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_certificate.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_challenge_auth.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_communication.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_digests.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_encap_challenge.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_encap_get_certificate.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_encap_get_digests.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_encap_key_update.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_encap_response.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_end_session.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_error.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_finish.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_handle_response_state.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_heartbeat.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_key_exchange.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_key_update.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_measurements.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_psk_exchange.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_psk_finish.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_receive_send.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_respond_if_ready.c
        ${LIBSPDM_DIR}/library/spdm_responder_lib/libspdm_rsp_version.c
    )

    zephyr_library_sources(
        ${LIBSPDM_DIR}/library/spdm_secured_message_lib/libspdm_secmes_context_data.c
        ${LIBSPDM_DIR}/library/spdm_secured_message_lib/libspdm_secmes_encode_decode.c
        ${LIBSPDM_DIR}/library/spdm_secured_message_lib/libspdm_secmes_key_exchange.c
        ${LIBSPDM_DIR}/library/spdm_secured_message_lib/libspdm_secmes_session.c
    )

    zephyr_library_sources_ifdef(
        LIBSPDM_TRANSPORT_MCTP
        ${LIBSPDM_DIR}/library/spdm_transport_mctp_lib/libspdm_mctp_common.c
        ${LIBSPDM_DIR}/library/spdm_transport_mctp_lib/libspdm_mctp_mctp.c
    )

    zephyr_library_sources_ifdef(
        LIBSPDM_TRANSPORT_PCIDOE
        ${LIBSPDM_DIR}/library/spdm_transport_pcidoe_lib/libspdm_doe_common.c
        ${LIBSPDM_DIR}/library/spdm_transport_pcidoe_lib/libspdm_doe_pcidoe.c
    )

    zephyr_library_sources(
        ${LIBSPDM_ZEPHYR_DIR}/debuglib/debuglib.c
        ${LIBSPDM_ZEPHYR_DIR}/platform_lib/time_zephyr.c
        ${LIBSPDM_ZEPHYR_DIR}/platform_lib/watchdog.c
        ${LIBSPDM_ZEPHYR_DIR}/spdm_device_secret_lib/lib.c
    ) 
endif()
