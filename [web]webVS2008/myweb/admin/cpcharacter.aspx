<%@ Page language="c#" Codebehind="cpcharacter.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpcharacter" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" style="WIDTH: 803px; HEIGHT: 780px" cellSpacing="1" cellPadding="3"
				width="803" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</b></A></p>
												</div>
												</FONT></FONT></td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" style="WIDTH: 550px; HEIGHT: 756px" cellSpacing="0" cellPadding="0"
							width="550" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left">
												<TABLE id="Table4" style="WIDTH: 559px; HEIGHT: 768px" cellSpacing="1" cellPadding="1"
													width="559" border="0">
													<TR>
														<TD style="WIDTH: 634px; HEIGHT: 22px" colSpan="2"><b>��ɫ��Ϣ��ԃ</b></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2">
															<table style="WIDTH: 464px; HEIGHT: 171px" width="464" border="0">
																<tr>
																	<td style="WIDTH: 75px">��̖</td>
																	<td><asp:textbox id="tbsuserid" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 75px">��ɫ��</td>
																	<td><asp:textbox id="tbschaname" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<TR>
																	<TD style="WIDTH: 75px; HEIGHT: 17px">��ɫ�ȼ�</TD>
																	<TD style="HEIGHT: 17px"><asp:textbox id="tbschalvmin" runat="server" Width="64px">0</asp:textbox>��
																		<asp:textbox id="tbschalvmax" runat="server" Width="64px">0</asp:textbox>֮�g</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 75px">��헌��Ժ�Ӌ</TD>
																	<TD><asp:textbox id="tbschapointmin" runat="server" Width="152px">0</asp:textbox>��
																		<asp:textbox id="tbschapointmax" runat="server" Width="152px">0</asp:textbox>֮�g</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 75px">�D����</TD>
																	<TD><asp:textbox id="tbscharesetmin" runat="server" Width="104px">0</asp:textbox>��
																		<asp:textbox id="tbscharesetmax" runat="server" Width="96px">0</asp:textbox>֮�g</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 75px"><FONT face="����"></FONT></TD>
																	<TD><asp:button id="btnsearch" runat="server" Text="��ԃ��ɫ��Ϣ"></asp:button>ע��ȫ�����ձ�ʾ�����еģ�Ч�ʕ��ܵ�</TD>
																</TR>
															</table>
														</TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2"><B>��ɫ��Ϣ�б�(���н�ɫ<%=rcount%>
																��)</B></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2"><asp:datagrid id="DataGrid1" runat="server" AutoGenerateColumns="False" AllowPaging="True">
																<Columns>
																	<asp:BoundColumn DataField="character_idx" HeaderText="��ɫIDX"></asp:BoundColumn>
																	<asp:BoundColumn DataField="user_idx" HeaderText="��̖IDX"></asp:BoundColumn>
																	<asp:BoundColumn DataField="character_name" HeaderText="��ɫ��"></asp:BoundColumn>
																	<asp:BoundColumn DataField="character_gender" HeaderText="�Ԅe"></asp:BoundColumn>
																	<asp:BoundColumn DataField="character_grade" HeaderText="�ȼ�"></asp:BoundColumn>
																	<asp:BoundColumn DataField="CHARACTER_PLAYTIME" HeaderText="�[��r�L(��)"></asp:BoundColumn>
																	<asp:BoundColumn DataField="webchareset" HeaderText="�D���Δ�"></asp:BoundColumn>
																	<asp:BoundColumn DataField="CHARACTER_LASTMODIFIED" HeaderText="�˳�����"></asp:BoundColumn>
																	<asp:ButtonColumn Text="�x��" ButtonType="PushButton" HeaderText="�x��" CommandName="Select"></asp:ButtonColumn>
																	<asp:ButtonColumn Text="&lt;div id=&quot;de&quot; onclick=&quot;JavaScript:return confirm('�_���h����?')&quot;&gt;�h��&lt;/div&gt;"
																		HeaderText="����" CommandName="Delete"></asp:ButtonColumn>
																</Columns>
																<PagerStyle Mode="NumericPages"></PagerStyle>
															</asp:datagrid></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 182px; HEIGHT: 22px" colSpan="2"><B>��ɫԔ����Ϣ</B></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">��̖IDX</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbuseridx" runat="server" Width="120px" ReadOnly="True" BackColor="#E0E0E0"></asp:textbox><asp:button id="btnsearuseridx" runat="server" Text="�鎤̖��Ϣ"></asp:button><FONT face="����">&nbsp;</FONT><FONT face="����">&nbsp;</FONT></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">��ɫIDX</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbchaidx" runat="server" Width="120px" ReadOnly="True" BackColor="#E0E0E0"></asp:textbox><asp:button id="btnsearchitem" runat="server" Text="��ɫ��Ʒ��"></asp:button><FONT face="����">&nbsp;
																<asp:button id="btnsearchst" runat="server" Text="��ͨ�}��"></asp:button>&nbsp;</FONT>
															<asp:button id="btnsearchbbst" runat="server" Text="�ٌ��}��"></asp:button><FONT face="����">&nbsp;</FONT><FONT face="����"></FONT></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">��ɫ��</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbchaname" runat="server" Width="120px"></asp:textbox><asp:button id="btnsearchskill" runat="server" Text="��ɫ�书���"></asp:button></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">���َ͕�</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbguild" runat="server" Width="88px" ReadOnly="True" BackColor="#E0E0E0"></asp:textbox><asp:button id="btnsearchguild" runat="server" Text="�͕���Ϣ" Enabled="False"></asp:button></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">���IDX</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbparty" runat="server" Width="88px" ReadOnly="True" BackColor="#E0E0E0"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 25px">�Ԅe</TD>
														<TD style="WIDTH: 636px; HEIGHT: 25px"><asp:dropdownlist id="ddsex" runat="server">
																<asp:ListItem Value="0">��</asp:ListItem>
																<asp:ListItem Value="1">Ů</asp:ListItem>
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 17px">�I</TD>
														<TD style="WIDTH: 55px; HEIGHT: 17px"><asp:dropdownlist id="ddjob" runat="server" Enabled="False">
																<asp:ListItem Value="���o��">���o��</asp:ListItem>
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 17px">����/�Oħ</TD>
														<TD style="WIDTH: 55px; HEIGHT: 17px"><asp:dropdownlist id="ddstage" runat="server">
																<asp:ListItem Value="0">��ͨ</asp:ListItem>
																<asp:ListItem Value="64">����</asp:ListItem>
																<asp:ListItem Value="128">�Oħ</asp:ListItem>
																<asp:ListItem Value="65">����</asp:ListItem>
																<asp:ListItem Value="129">Óħ</asp:ListItem>
	
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 9px">��ꑵ؈D</TD>
														<TD style="WIDTH: 55px; HEIGHT: 9px"><asp:dropdownlist id="ddmap" runat="server"></asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">�ȼ�</TD>
														<TD><asp:textbox id="tbchalv" runat="server" Width="56px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">�[���</TD>
														<TD><asp:textbox id="tbmoney" runat="server" Width="152px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">�D���Δ�</TD>
														<TD style="WIDTH: 55px; HEIGHT: 22px"><asp:textbox id="tbchareset" runat="server" Width="80px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 22px">�����Δ�</TD>
														<TD style="WIDTH: 55px; HEIGHT: 22px"><asp:textbox id="tbnewname" runat="server" Width="80px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">����</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbgengoal" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">����</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbdex" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">�w�|</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbsta" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 3px">����</TD>
														<TD style="WIDTH: 55px; HEIGHT: 3px"><asp:textbox id="tbsimmak" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">ʣ���c</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbpoint" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">�����c</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbabilityexp" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 24px">����</TD>
														<TD style="WIDTH: 55px; HEIGHT: 24px"><asp:textbox id="tbbadfame" runat="server" Width="128px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 19px">�˳�����</TD>
														<TD style="WIDTH: 55px; HEIGHT: 19px"><asp:textbox id="tblogouttime" runat="server" ReadOnly="True" Enabled="False" BackColor="#E0E0E0"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 19px">���[��r�g</TD>
														<TD style="WIDTH: 55px; HEIGHT: 19px"><asp:textbox id="tbplaytime" runat="server"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 84px; HEIGHT: 27px"></TD>
														<TD style="WIDTH: 55px; HEIGHT: 27px"><asp:button id="btnedit" runat="server" Text="�޸Ľ�ɫ��Ϣ"></asp:button></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px" vAlign="top" colSpan="2"></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 19px" align="left" colSpan="2"></TD>
													</TR>
												</TABLE>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
