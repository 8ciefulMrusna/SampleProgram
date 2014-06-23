//**********************************************************************************
//* All Rights Reserved, Copyright (C) 2007,2010 Hitachi Solutions,Ltd.
//**********************************************************************************

//**********************************************************************************
//* �N���X��        �FWindowsAPIErrorException
//* �N���X���{�ꖼ  �FWin32���ʗ�O
//*
//* �쐬��          �F���Z ����
//* �X�V����        �F
//*
//*  ����        �X�V��            ���e
//*  ----------  ----------------  -------------------------------------------------
//*  2010/10/26  ����  ���        �V�K�쐬
//**********************************************************************************

using System;

namespace Touryo.Infrastructure.Public.Win32
{
    /// <summary>Win32���ʗ�O</summary>
    public class WindowsAPIErrorException : ApplicationException
    {
        /// <summary>�G���[���b�Z�[�W�̃e���v���[�g</summary>
        public static readonly string MessageTemplate
            = "Windows API��{0}�֐��Ăяo���Ɏ��s���܂����B";

        /// <summary>ErrorCodes</summary>
        private CmnWin32.ErrorCodes _errorCode = 0;

        /// <summary>ErrorCodes</summary>
        public CmnWin32.ErrorCodes ErrorCode
        {
            get
            {
                return this._errorCode;
            }
        }

        /// <summary>�R���X�g���N�^�P</summary>
        /// <param name="error">ErrorCodes</param>
        public WindowsAPIErrorException(CmnWin32.ErrorCodes error)
            : base()
        {
            this._errorCode = error;
        }

        /// <summary>�R���X�g���N�^�Q</summary>
        /// <param name="error">ErrorCodes</param>
        /// <param name="message">���b�Z�[�W</param>
        public WindowsAPIErrorException(
            CmnWin32.ErrorCodes error, string message)
            : base(message)
        {
            this._errorCode = error;
        }

        /// <summary>�R���X�g���N�^�R</summary>
        /// <param name="error">ErrorCodes</param>
        /// <param name="message">���b�Z�[�W</param>
        /// <param name="inner">������O</param>
        public WindowsAPIErrorException(
            CmnWin32.ErrorCodes error, string message, System.Exception inner)
            : base(message, inner)
        {
            this._errorCode = error;
        }

        /// <summary>�R���X�g���N�^�S</summary>
        /// <param name="info">SerializationInfo</param>
        /// <param name="context">StreamingContext</param>
        /// <remarks>
        /// �����[�e�B���O �T�[�o����̓`�d�ɕK�v�ȃR���X�g���N�^�B
        /// </remarks>
        protected WindowsAPIErrorException(
            System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
}
