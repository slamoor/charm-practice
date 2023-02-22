/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_2_closure : public SDAG::Closure {
      

      done_2_closure() {
        init();
      }
      done_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~done_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::recv_3_closure : public SDAG::Closure {
            long n;
            int ind;
            int num;
            int res;


      recv_3_closure() {
        init();
      }
      recv_3_closure(CkMigrateMessage*) {
        init();
      }
            long & getP0() { return n;}
            int & getP1() { return ind;}
            int & getP2() { return num;}
            int & getP3() { return res;}
      void pup(PUP::er& __p) {
        __p | n;
        __p | ind;
        __p | num;
        __p | res;
        packClosure(__p);
      }
      virtual ~recv_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(recv_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Hello::ComputePrimeArray_2_closure : public SDAG::Closure {
            long *n;
            int inputSize;

      CkMarshallMsg* _impl_marshall;
      char* _impl_buf_in;
      int _impl_buf_size;

      ComputePrimeArray_2_closure() {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
      ComputePrimeArray_2_closure(CkMigrateMessage*) {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
            long *& getP0() { return n;}
            int & getP1() { return inputSize;}
      void pup(PUP::er& __p) {
        __p | inputSize;
        packClosure(__p);
        __p | _impl_buf_size;
        bool hasMsg = (_impl_marshall != 0); __p | hasMsg;
        if (hasMsg) CkPupMessage(__p, (void**)&_impl_marshall);
        else PUParray(__p, _impl_buf_in, _impl_buf_size);
        if (__p.isUnpacking()) {
          char *impl_buf = _impl_marshall ? _impl_marshall->msgBuf : _impl_buf_in;
          PUP::fromMem implP(impl_buf);
  int impl_off_n, impl_cnt_n;
  implP|impl_off_n;
  implP|impl_cnt_n;
  PUP::detail::TemporaryObjectHolder<int> inputSize;
  implP|inputSize;
          impl_buf+=CK_ALIGN(implP.size(),16);
          n = (long *)(impl_buf+impl_off_n);
        }
      }
      virtual ~ComputePrimeArray_2_closure() {
        if (_impl_marshall) CmiFree(UsrToEnv(_impl_marshall));
      }
      PUPable_decl(SINGLE_ARG(ComputePrimeArray_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void recv(long n, int ind, int num, int res);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done();
 */
void CProxy_Main::done(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_done_void() {
  int epidx = CkRegisterEp("done()",
      reinterpret_cast<CkCallFnPtr>(_call_done_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->done();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::done_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recv(long n, int ind, int num, int res);
 */
void CProxy_Main::recv(long n, int ind, int num, int res, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: long n, int ind, int num, int res
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|ind;
    implP|num;
    implP|res;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|ind;
    implP|num;
    implP|res;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_recv_marshall3(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_recv_marshall3(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_recv_marshall3(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_recv_marshall3() {
  int epidx = CkRegisterEp("recv(long n, int ind, int num, int res)",
      reinterpret_cast<CkCallFnPtr>(_call_recv_marshall3), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_recv_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_recv_marshall3);

  return epidx;
}

void CkIndex_Main::_call_recv_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: long n, int ind, int num, int res*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<long> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<int> ind;
  implP|ind;
  PUP::detail::TemporaryObjectHolder<int> num;
  implP|num;
  PUP::detail::TemporaryObjectHolder<int> res;
  implP|res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->recv(std::move(n.t), std::move(ind.t), std::move(num.t), std::move(res.t));
}
int CkIndex_Main::_callmarshall_recv_marshall3(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: long n, int ind, int num, int res*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<long> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<int> ind;
  implP|ind;
  PUP::detail::TemporaryObjectHolder<int> num;
  implP|num;
  PUP::detail::TemporaryObjectHolder<int> res;
  implP|res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->recv(std::move(n.t), std::move(ind.t), std::move(num.t), std::move(res.t));
  return implP.size();
}
void CkIndex_Main::_marshallmessagepup_recv_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: long n, int ind, int num, int res*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<long> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<int> ind;
  implP|ind;
  PUP::detail::TemporaryObjectHolder<int> num;
  implP|num;
  PUP::detail::TemporaryObjectHolder<int> res;
  implP|res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("ind");
  implDestP|ind;
  if (implDestP.hasComments()) implDestP.comment("num");
  implDestP|num;
  if (implDestP.hasComments()) implDestP.comment("res");
  implDestP|res;
}
PUPable_def(SINGLE_ARG(Closure_Main::recv_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done();
  idx_done_void();

  // REG: void recv(long n, int ind, int num, int res);
  idx_recv_marshall3();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Hello: ArrayElement{
Hello();
void ComputePrimeArray(const long *n, int inputSize);
Hello(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Hello::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Hello::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_Hello::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_Hello::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_Hello::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_Hello::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_Hello::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello();
 */
void CProxyElement_Hello::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Hello::idx_Hello_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ComputePrimeArray(const long *n, int inputSize);
 */
void CProxyElement_Hello::ComputePrimeArray(const long *n, int inputSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const long *n, int inputSize
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_n, impl_cnt_n;
  impl_off_n=impl_off=CK_ALIGN(impl_off,sizeof(long));
  impl_off+=(impl_cnt_n=sizeof(long)*(5));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_n,n,impl_cnt_n);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Hello::idx_ComputePrimeArray_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello();
 */
CkArrayID CProxy_Hello::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Hello::idx_Hello_void(), opts);
  return gId;
}
void CProxy_Hello::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Hello::idx_Hello_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_Hello::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Hello::idx_Hello_void(), opts);
  return gId;
}
void CProxy_Hello::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Hello::idx_Hello_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_Hello::reg_Hello_void() {
  int epidx = CkRegisterEp("Hello()",
      reinterpret_cast<CkCallFnPtr>(_call_Hello_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Hello::_call_Hello_void(void* impl_msg, void* impl_obj_void)
{
  Hello* impl_obj = static_cast<Hello*>(impl_obj_void);
  new (impl_obj_void) Hello();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ComputePrimeArray(const long *n, int inputSize);
 */
void CProxy_Hello::ComputePrimeArray(const long *n, int inputSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const long *n, int inputSize
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_n, impl_cnt_n;
  impl_off_n=impl_off=CK_ALIGN(impl_off,sizeof(long));
  impl_off+=(impl_cnt_n=sizeof(long)*(5));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_n,n,impl_cnt_n);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Hello::idx_ComputePrimeArray_marshall2(),0);
}

// Entry point registration function
int CkIndex_Hello::reg_ComputePrimeArray_marshall2() {
  int epidx = CkRegisterEp("ComputePrimeArray(const long *n, int inputSize)",
      reinterpret_cast<CkCallFnPtr>(_call_ComputePrimeArray_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_ComputePrimeArray_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_ComputePrimeArray_marshall2);

  return epidx;
}

void CkIndex_Hello::_call_ComputePrimeArray_marshall2(void* impl_msg, void* impl_obj_void)
{
  Hello* impl_obj = static_cast<Hello*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const long *n, int inputSize*/
  PUP::fromMem implP(impl_buf);
  int impl_off_n, impl_cnt_n;
  implP|impl_off_n;
  implP|impl_cnt_n;
  PUP::detail::TemporaryObjectHolder<int> inputSize;
  implP|inputSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  long *n=(long *)(impl_buf+impl_off_n);
  impl_obj->ComputePrimeArray(n, std::move(inputSize.t));
}
int CkIndex_Hello::_callmarshall_ComputePrimeArray_marshall2(char* impl_buf, void* impl_obj_void) {
  Hello* impl_obj = static_cast<Hello*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const long *n, int inputSize*/
  PUP::fromMem implP(impl_buf);
  int impl_off_n, impl_cnt_n;
  implP|impl_off_n;
  implP|impl_cnt_n;
  PUP::detail::TemporaryObjectHolder<int> inputSize;
  implP|inputSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  long *n=(long *)(impl_buf+impl_off_n);
  impl_obj->ComputePrimeArray(n, std::move(inputSize.t));
  return implP.size();
}
void CkIndex_Hello::_marshallmessagepup_ComputePrimeArray_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const long *n, int inputSize*/
  PUP::fromMem implP(impl_buf);
  int impl_off_n, impl_cnt_n;
  implP|impl_off_n;
  implP|impl_cnt_n;
  PUP::detail::TemporaryObjectHolder<int> inputSize;
  implP|inputSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  long *n=(long *)(impl_buf+impl_off_n);
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP.synchronize(PUP::sync_begin_array);
  for (int impl_i=0;impl_i*(sizeof(*n))<impl_cnt_n;impl_i++) {
    implDestP.synchronize(PUP::sync_item);
    implDestP|n[impl_i];
  }
  implDestP.synchronize(PUP::sync_end_array);
  if (implDestP.hasComments()) implDestP.comment("inputSize");
  implDestP|inputSize;
}
PUPable_def(SINGLE_ARG(Closure_Hello::ComputePrimeArray_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_Hello::reg_Hello_CkMigrateMessage() {
  int epidx = CkRegisterEp("Hello(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Hello_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_Hello::_call_Hello_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Hello> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ComputePrimeArray(const long *n, int inputSize);
 */
void CProxySection_Hello::ComputePrimeArray(const long *n, int inputSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const long *n, int inputSize
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_n, impl_cnt_n;
  impl_off_n=impl_off=CK_ALIGN(impl_off,sizeof(long));
  impl_off+=(impl_cnt_n=sizeof(long)*(5));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_n;
    implP|impl_cnt_n;
    implP|inputSize;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_n,n,impl_cnt_n);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Hello::idx_ComputePrimeArray_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Hello(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Hello::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Hello();
  idx_Hello_void();
  CkRegisterDefaultCtor(__idx, idx_Hello_void());

  // REG: void ComputePrimeArray(const long *n, int inputSize);
  idx_ComputePrimeArray_marshall2();

  // REG: Hello(CkMigrateMessage* impl_msg);
  idx_Hello_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Hello_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerhello(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void recv(long n, int ind, int num, int res);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Hello: ArrayElement{
Hello();
void ComputePrimeArray(const long *n, int inputSize);
Hello(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Hello::__register("Hello", sizeof(Hello));

}
extern "C" void CkRegisterMainModule(void) {
  _registerhello();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Hello::virtual_pup(PUP::er &p) {
    recursive_pup<Hello>(dynamic_cast<Hello*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
